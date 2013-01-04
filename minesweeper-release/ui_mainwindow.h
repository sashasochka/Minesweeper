/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jan 5 00:39:46 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_Minesweeper;
    QAction *actionNew_Game;
    QAction *actionOptions;
    QAction *actionExit;
    QAction *actionView_Help;
    QAction *actionStastics;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(434, 326);
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextOnly);
        actionAbout_Minesweeper = new QAction(MainWindow);
        actionAbout_Minesweeper->setObjectName(QStringLiteral("actionAbout_Minesweeper"));
        actionAbout_Minesweeper->setEnabled(true);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionOptions->setEnabled(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionView_Help = new QAction(MainWindow);
        actionView_Help->setObjectName(QStringLiteral("actionView_Help"));
        actionView_Help->setEnabled(true);
        actionStastics = new QAction(MainWindow);
        actionStastics->setObjectName(QStringLiteral("actionStastics"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 434, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionNew_Game);
        menuMenu->addSeparator();
        menuMenu->addAction(actionOptions);
        menuMenu->addAction(actionStastics);
        menuMenu->addSeparator();
        menuMenu->addAction(actionExit);
        menuHelp->addAction(actionView_Help);
        menuHelp->addAction(actionAbout_Minesweeper);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Minesweeper", 0));
#ifndef QT_NO_WHATSTHIS
        MainWindow->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionAbout_Minesweeper->setText(QApplication::translate("MainWindow", "About Minesweeper", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionNew_Game->setShortcut(QApplication::translate("MainWindow", "F2", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        actionOptions->setShortcut(QApplication::translate("MainWindow", "F5", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionView_Help->setText(QApplication::translate("MainWindow", "Changelog", 0));
        actionView_Help->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionStastics->setText(QApplication::translate("MainWindow", "Statistics", 0));
        actionStastics->setShortcut(QApplication::translate("MainWindow", "F4", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Game", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
