#-------------------------------------------------
#
# Project created by QtCreator 2013-01-04T15:17:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = minesweeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    field.cpp \
    about.cpp \
    windialog.cpp \
    optionsdialog.cpp \
    statisticswidget.cpp \
    uintvalidator.cpp \
    changeloginfo.cpp \
    defeat.cpp \
    cell.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    field.h \
    about.h \
    windialog.h \
    optionsdialog.h \
    statisticswidget.h \
    uintvalidator.h \
    changeloginfo.h \
    defeat.h \
    cell.h \
    settings.h

FORMS    += mainwindow.ui \
    about.ui \
    windialog.ui \
    statistics.ui \
    changeloginfo.ui \
    defeat.ui

RESOURCES += \
    resourses.qrc

OTHER_FILES += \
    styles.qss \
    minesweeper_uk.ts \
    minesweeper_en.ts \
