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
    minesweeper_uk.qm \
    minesweeper_en.ts \
    minesweeper_en.qm \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/values-ro/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/values-pl/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-es/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-id/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-rs/strings.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/version.xml \
    android/AndroidManifest.xml
