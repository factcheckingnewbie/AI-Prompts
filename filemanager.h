#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QTreeView>
#include <QListView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QFileSystemModel>
#include <QStringListModel>

class FileManager : public QMainWindow
{
    Q_OBJECT

public:
    FileManager(QWidget *parent = nullptr);
    ~FileManager();

private slots:
    void onDirectorySelected(const QModelIndex &index);
    void onCommandEntered();

private:
    void setupUI();
    void updateListViews(const QString &directoryPath);
    
    QWidget *centralWidget;
    QTreeView *treeView;
    QListView *listView1;
    QListView *listView2;
    QLineEdit *commandLineEdit;
    
    QFileSystemModel *fileSystemModel;
    QStringListModel *listModel1;
    QStringListModel *listModel2;
    
    QStringList currentFiles;
};

#endif // FILEMANAGER_H