#include "filemanager.h"
#include <QHeaderView>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

FileManager::FileManager(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(nullptr)
    , mainLayout(nullptr)
    , splitter(nullptr)
    , treeView(nullptr)
    , rightWidget(nullptr)
    , rightLayout(nullptr)
    , rightSplitter(nullptr)
    , listView1(nullptr)
    , listView2(nullptr)
    , commandWidget(nullptr)
    , commandLayout(nullptr)
    , commandLabel(nullptr)
    , commandInput(nullptr)
    , executeButton(nullptr)
    , fileSystemModel(nullptr)
    , standardModel(nullptr)
{
    setupUI();
    setupModels();
    setupConnections();
    
    // Set window properties
    setWindowTitle("Qt File Manager");
    resize(1000, 700);
}

FileManager::~FileManager()
{
    // Qt handles cleanup automatically through parent-child relationships
}

void FileManager::setupUI()
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Main horizontal layout
    mainLayout = new QHBoxLayout(centralWidget);
    splitter = new QSplitter(Qt::Horizontal, this);
    mainLayout->addWidget(splitter);
    
    // Left side - Directory tree
    treeView = new QTreeView();
    splitter->addWidget(treeView);
    
    // Right side widget
    rightWidget = new QWidget();
    rightLayout = new QVBoxLayout(rightWidget);
    splitter->addWidget(rightWidget);
    
    // Right side splitter for the two list views
    rightSplitter = new QSplitter(Qt::Horizontal);
    rightLayout->addWidget(rightSplitter);
    
    // List views
    listView1 = new QListView();
    listView2 = new QListView();
    rightSplitter->addWidget(listView1);
    rightSplitter->addWidget(listView2);
    
    // Command area
    commandWidget = new QWidget();
    commandLayout = new QHBoxLayout(commandWidget);
    rightLayout->addWidget(commandWidget);
    
    commandLabel = new QLabel("Command:");
    commandInput = new QLineEdit();
    executeButton = new QPushButton("Execute");
    
    commandLayout->addWidget(commandLabel);
    commandLayout->addWidget(commandInput);
    commandLayout->addWidget(executeButton);
    
    // Set default command
    commandInput->setText("get filename");
    
    // Set splitter proportions
    splitter->setSizes({300, 700});
    rightSplitter->setSizes({350, 350});
}

void FileManager::setupModels()
{
    // Setup file system model for tree view and list view 1
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    
    // Configure tree view
    treeView->setModel(fileSystemModel);
    treeView->setRootIndex(fileSystemModel->index(QDir::homePath()));
    treeView->setColumnWidth(0, 300);
    treeView->hideColumn(1); // Hide size column
    treeView->hideColumn(2); // Hide type column
    treeView->hideColumn(3); // Hide date column
    
    // Configure list view 1 (shows files from selected directory)
    listView1->setModel(fileSystemModel);
    
    // Setup standard item model for list view 2 (modifiable)
    standardModel = new QStandardItemModel(this);
    standardModel->setHorizontalHeaderLabels({"Modified Filenames"});
    listView2->setModel(standardModel);
    
    // Set initial directory to home
    currentDirectory = QDir::homePath();
    listView1->setRootIndex(fileSystemModel->index(currentDirectory));
    updateListView2();
}

void FileManager::setupConnections()
{
    // Connect tree view selection to update list views
    connect(treeView, &QTreeView::clicked, this, &FileManager::onDirectoryClicked);
    
    // Connect list view 1 selection
    connect(listView1, &QListView::clicked, this, &FileManager::onFileClicked);
    
    // Connect execute button
    connect(executeButton, &QPushButton::clicked, this, &FileManager::executeCommand);
    
    // Connect Enter key in command input to execute
    connect(commandInput, &QLineEdit::returnPressed, this, &FileManager::executeCommand);
}

void FileManager::onDirectoryClicked(const QModelIndex &index)
{
    if (!fileSystemModel->isDir(index)) {
        return;
    }
    
    QString path = fileSystemModel->filePath(index);
    currentDirectory = path;
    
    // Update list view 1 to show files in selected directory
    listView1->setRootIndex(index);
    
    // Update list view 2 with the same files
    updateListView2();
    
    qDebug() << "Directory selected:" << path;
}

void FileManager::onFileClicked(const QModelIndex &index)
{
    if (fileSystemModel->isDir(index)) {
        return;
    }
    
    QString fileName = fileSystemModel->fileName(index);
    selectedFile = fileName;
    
    qDebug() << "File selected:" << fileName;
}

void FileManager::executeCommand()
{
    QString command = commandInput->text().trimmed();
    
    if (command.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a command.");
        return;
    }
    
    if (selectedFile.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a file first.");
        return;
    }
    
    // For now, implement simple "get filename" command
    if (command.toLower() == "get filename") {
        // Find the corresponding item in standardModel and update it
        for (int i = 0; i < standardModel->rowCount(); ++i) {
            QStandardItem *item = standardModel->item(i);
            if (item && item->data(Qt::UserRole).toString() == selectedFile) {
                // Update the display text to show the selected filename
                item->setText(QString("Selected: %1").arg(selectedFile));
                qDebug() << "Updated item for file:" << selectedFile;
                break;
            }
        }
    } else {
        QMessageBox::information(this, "Info", 
            QString("Command '%1' not implemented yet.\nSelected file: %2")
            .arg(command).arg(selectedFile));
    }
}

void FileManager::updateListView2()
{
    // Clear the standard model
    standardModel->clear();
    standardModel->setHorizontalHeaderLabels({"Modified Filenames"});
    
    // Get the directory index for the current directory
    QModelIndex dirIndex = fileSystemModel->index(currentDirectory);
    if (!dirIndex.isValid()) {
        return;
    }
    
    // Populate standard model with files from current directory
    int rowCount = fileSystemModel->rowCount(dirIndex);
    for (int i = 0; i < rowCount; ++i) {
        QModelIndex childIndex = fileSystemModel->index(i, 0, dirIndex);
        if (!fileSystemModel->isDir(childIndex)) {
            QString fileName = fileSystemModel->fileName(childIndex);
            QStandardItem *item = new QStandardItem(fileName);
            item->setData(fileName, Qt::UserRole); // Store original filename
            standardModel->appendRow(item);
        }
    }
    
    qDebug() << "Updated ListView2 with files from:" << currentDirectory;
}