cmake_minimum_required(VERSION 3.16)

project(FileManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Enable automatic handling of Qt5 meta-object compiler
set(CMAKE_AUTOMOC ON)

# Add executable
add_executable(FileManager
    main.cpp
    filemanager.cpp
    filemanager.h
)

# Link Qt5 libraries
target_link_libraries(FileManager Qt5::Core Qt5::Widgets)