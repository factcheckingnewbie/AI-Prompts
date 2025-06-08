#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include <QTreeView>
#include <QListView>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QLabel>

class FileManager : public QMainWindow
{
    Q_OBJECT

public:
    FileManager(QWidget *parent = nullptr);
    ~FileManager();

private slots:
    void onDirectoryClicked(const QModelIndex &index);
    void onFileClicked(const QModelIndex &index);
    void executeCommand();

private:
    void setupUI();
    void setupModels();
    void setupConnections();
    void updateListView2();

    // UI Components
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
    QSplitter *splitter;
    
    // Left side - Directory tree
    QTreeView *treeView;
    
    // Right side - File lists and command area
    QWidget *rightWidget;
    QVBoxLayout *rightLayout;
    QSplitter *rightSplitter;
    
    QListView *listView1;  // Shows files with QFileSystemModel
    QListView *listView2;  // Shows files with QStandardItemModel (modifiable)
    
    // Command area
    QWidget *commandWidget;
    QHBoxLayout *commandLayout;
    QLabel *commandLabel;
    QLineEdit *commandInput;
    QPushButton *executeButton;
    
    // Models
    QFileSystemModel *fileSystemModel;
    QStandardItemModel *standardModel;
    
    // Current selections
    QString currentDirectory;
    QString selectedFile;
};

#endif // FILEMANAGER_H