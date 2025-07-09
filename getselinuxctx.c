#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <selinux/selinux.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

void print_context(const char *file, int follow_link) {
    char *context = NULL;
    int ret = follow_link ? getfilecon(file, &context) : lgetfilecon(file, &context);
    if (ret >= 0 && context) {
        printf("%s", context);
        freecon(context);
    } else {
        printf("?");
    }
}

int main(int argc, char **argv) {
    if (argc == 3 && strcmp(argv[1], "-s") == 0) {
        print_context(argv[2], 0);
        printf("\n");
        return 0;
    }
    if (argc == 3 && strcmp(argv[1], "-t") == 0) {
        print_context(argv[2], 1);
        printf("\n");
        return 0;
    }
    if (argc == 1) {
        char buf[PATH_MAX], link[PATH_MAX];
        ssize_t len;
        char *path = NULL;
        struct stat st;
        int first = 1;

        // Read from stdin
        if (fgets(buf, sizeof(buf), stdin) == NULL) return 1;
        buf[strcspn(buf, "\n")] = 0;
        path = buf;

        // Walk symlink chain
        while (1) {
            lstat(path, &st);
            if (S_ISLNK(st.st_mode)) {
                if (!first) printf(" ");
                print_context(path, 0);
                first = 0;

                len = readlink(path, link, sizeof(link)-1);
                if (len < 0) break;
                link[len] = 0;
                if (link[0] == '/') {
                    path = link;
                } else {
                    char *slash = strrchr(path, '/');
                    if (slash) {
                        size_t dirlen = slash - path + 1;
                        char tmp[PATH_MAX];
                        strncpy(tmp, path, dirlen);
                        tmp[dirlen] = 0;
                        snprintf(buf, sizeof(buf), "%s%s", tmp, link);
                        path = buf;
                    } else {
                        strcpy(buf, link);
                        path = buf;
                    }
                }
            } else {
                if (!first) printf(" ");
                print_context(path, 1);
                break;
            }
        }
        printf("\n");
        return 0;
    }
    fprintf(stderr, "usage: %s [-s file|-t file]\n", argv[0]);
    return 1;
}