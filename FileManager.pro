QT += core widgets

CONFIG += c++17

TARGET = FileManager
TEMPLATE = app

SOURCES += \
    main.cpp \
    filemanager.cpp

HEADERS += \
    filemanager.h

# Destination directory for the executable
DESTDIR = build

# Temporary directories
OBJECTS_DIR = build/obj
MOC_DIR = build/moc