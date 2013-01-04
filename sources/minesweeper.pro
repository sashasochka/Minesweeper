#-------------------------------------------------
#
# Project created by QtCreator 2011-09-10T13:03:05
#
#-------------------------------------------------

QT       += core gui

TARGET = minesweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cell.cpp \
    field.cpp \
    defeat.cpp \
    windialog.cpp \
    optionsdialog.cpp \
    about.cpp \
    uintvalidator.cpp \
    changeloginfo.cpp \
    statisticswidget.cpp

HEADERS  += mainwindow.h \
    cell.h \
    field.h \
    defeat.h \
    windialog.h \
    optionsdialog.h \
    about.h \
    uintvalidator.h \
    changeloginfo.h \
    statisticswidget.h

FORMS    += mainwindow.ui \
    defeat.ui \
    windialog.ui \
    about.ui \
    changeloginfo.ui \
    statistics.ui

RESOURCES += \
    resourses.qrc

TRANSLATIONS += \
    minesweeper_en.ts \
    minesweeper_uk.ts


















































