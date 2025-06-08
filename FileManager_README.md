# Qt File Manager Application

A Qt-based file manager application with dual-view functionality and command execution capabilities.

## Features

- **TreeView Navigation**: Browse the file system directory structure on the left panel
- **Dual ListView Display**: 
  - ListView 1: Shows files in the currently selected directory (read-only)
  - ListView 2: Shows modifiable view of the same files
- **Command Execution**: Execute commands on selected files via command input box
- **Extensible Design**: Ready for future enhancements with SELinux context support

## Current Commands

- `get filename`: Updates the selected file's display in ListView 2 to show it as selected

## Building the Application

### Using CMake (Recommended)

```bash
mkdir build
cd build
cmake ..
make
./FileManager
```

### Using qmake (Alternative)

```bash
qmake FileManager.pro
make
./build/FileManager
```

## Requirements

- Qt5 (Core, Widgets modules)
- CMake 3.16+ or qmake
- C++17 compatible compiler

## File Structure

- `main.cpp` - Application entry point
- `filemanager.h` - Main window class header
- `filemanager.cpp` - Main window implementation
- `CMakeLists.txt` - CMake build configuration
- `FileManager.pro` - qmake build configuration

## Usage

1. Navigate directories using the TreeView on the left
2. Select files from ListView 1 (files in current directory)
3. Enter commands in the command input box at the bottom
4. Click "Execute" or press Enter to run the command
5. View results in ListView 2

## Future Enhancements

The application is designed to be extended with:
- SELinux context operations
- matchpathcon functionality
- Additional file management commands
- Custom file operations

## Architecture

- Uses `QFileSystemModel` for TreeView and ListView 1 (system integration)
- Uses `QStandardItemModel` for ListView 2 (allows modifications)
- Signal/slot connections for UI interaction
- Modular design for easy extension