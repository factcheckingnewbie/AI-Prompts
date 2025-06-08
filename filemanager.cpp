#include "filemanager.h"
#include <QDir>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>
#include <QLabel>
#include <QStringList>
#include <QApplication>

FileManager::FileManager(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    
    // Initialize models
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::currentPath());
    fileSystemModel->setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    
    listModel1 = new QStringListModel(this);
    listModel2 = new QStringListModel(this);
    
    // Set models to views
    treeView->setModel(fileSystemModel);
    treeView->setRootIndex(fileSystemModel->index(QDir::currentPath()));
    treeView->hideColumn(1); // Hide size column
    treeView->hideColumn(2); // Hide type column  
    treeView->hideColumn(3); // Hide date column
    
    listView1->setModel(listModel1);
    listView2->setModel(listModel2);
    
    // Connect signals
    connect(treeView->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &FileManager::onDirectorySelected);
    connect(commandLineEdit, &QLineEdit::returnPressed,
            this, &FileManager::onCommandEntered);
    
    // Initialize with current directory
    updateListViews(QDir::currentPath());
}

FileManager::~FileManager()
{
}

void FileManager::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // Create splitter for main content
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, this);
    
    // Create tree view for directory navigation
    treeView = new QTreeView(this);
    treeView->setHeaderHidden(true);
    
    // Create right side layout for list views
    QWidget *rightWidget = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);
    
    // Create horizontal layout for the two list views
    QHBoxLayout *listLayout = new QHBoxLayout();
    
    // Create list views
    QVBoxLayout *listView1Layout = new QVBoxLayout();
    QLabel *listView1Label = new QLabel("ListView 1", this);
    listView1 = new QListView(this);
    listView1Layout->addWidget(listView1Label);
    listView1Layout->addWidget(listView1);
    
    QVBoxLayout *listView2Layout = new QVBoxLayout();
    QLabel *listView2Label = new QLabel("ListView 2", this);
    listView2 = new QListView(this);
    listView2Layout->addWidget(listView2Label);
    listView2Layout->addWidget(listView2);
    
    listLayout->addLayout(listView1Layout);
    listLayout->addLayout(listView2Layout);
    
    // Create command line edit
    QLabel *commandLabel = new QLabel("Command:", this);
    commandLineEdit = new QLineEdit(this);
    commandLineEdit->setPlaceholderText("Enter command here...");
    
    // Add to right layout
    rightLayout->addLayout(listLayout);
    rightLayout->addWidget(commandLabel);
    rightLayout->addWidget(commandLineEdit);
    
    // Add to splitter
    mainSplitter->addWidget(treeView);
    mainSplitter->addWidget(rightWidget);
    
    // Set splitter proportions
    mainSplitter->setSizes({200, 600});
    
    // Add to main layout
    mainLayout->addWidget(mainSplitter);
    
    // Set window properties
    setWindowTitle("Qt File Manager");
    resize(800, 600);
}

void FileManager::onDirectorySelected(const QModelIndex &index)
{
    QString directoryPath = fileSystemModel->filePath(index);
    updateListViews(directoryPath);
}

void FileManager::updateListViews(const QString &directoryPath)
{
    QDir directory(directoryPath);
    currentFiles = directory.entryList(QDir::Files, QDir::Name);
    
    // Update both list views with the same file list
    listModel1->setStringList(currentFiles);
    listModel2->setStringList(currentFiles);
}

void FileManager::onCommandEntered()
{
    QString command = commandLineEdit->text().trimmed();
    
    if (command.isEmpty()) {
        return;
    }
    
    // Basic command implementation: sync filenames from ListView1 to ListView2
    // Get the currently selected item in ListView1
    QModelIndex selectedIndex = listView1->currentIndex();
    if (selectedIndex.isValid()) {
        QString selectedFileName = listModel1->data(selectedIndex, Qt::DisplayRole).toString();
        
        // Update ListView2 to match the filename from ListView1
        QStringList listView2Files;
        
        // For each file, if the command references the selected file, 
        // update ListView2 to show the same filename
        for (const QString &file : currentFiles) {
            if (file == selectedFileName) {
                listView2Files.append(selectedFileName);
            } else {
                listView2Files.append(file);
            }
        }
        
        // Update ListView2 with the modified list
        listModel2->setStringList(listView2Files);
    }
    
    // Clear the command line
    commandLineEdit->clear();
}