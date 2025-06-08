# AI Prompts Repository

This repository contains AI prompts and a Qt File Manager application.

## Qt File Manager

A basic file manager application built with Qt5 that serves as a foundation for future SELinux context and matchpacon customizations.

### Features

- **TreeView**: Directory navigation showing the directory structure
- **Two ListViews**: Both display files from the selected directory
- **Command Box**: LineEdit for entering commands that operate on selected files
- **Directory Synchronization**: When a directory is selected in TreeView, both ListViews update to show files
- **File Selection Commands**: Commands can reference selected files and sync filenames between ListViews

### Building and Running

Prerequisites:
- Qt5 development libraries
- CMake
- C++ compiler

Build instructions:
```bash
mkdir build
cd build
cmake ..
make
./qtfilemanager
```

### Usage

1. Use the TreeView on the left to navigate directories
2. Both ListViews will automatically update when you select a directory
3. Select files in ListView 1 and use commands in the command box
4. Commands will update ListView 2 to match filename selections from ListView 1

### Architecture

- `main.cpp`: Application entry point
- `filemanager.h`: Main window class declaration with UI components
- `filemanager.cpp`: Implementation of file manager functionality
- `CMakeLists.txt`: Build configuration

The application focuses only on filenames without additional file attributes, making it suitable as a foundation for SELinux context management tools.
