cmake_minimum_required(VERSION 3.16)
project(QtFileManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)

set(SOURCES
    main.cpp
    filemanager.cpp
)

set(HEADERS
    filemanager.h
)

add_executable(qtfilemanager ${SOURCES} ${HEADERS})

target_link_libraries(qtfilemanager Qt5::Core Qt5::Widgets)