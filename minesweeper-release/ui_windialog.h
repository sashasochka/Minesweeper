/********************************************************************************
** Form generated from reading UI file 'windialog.ui'
**
** Created: Mon Jan 7 12:17:13 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDIALOG_H
#define UI_WINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *time;
    QLabel *date;
    QSpacerItem *verticalSpacer;
    QLabel *bestTime;
    QLabel *gamesPlayed;
    QLabel *gamesWon;
    QLabel *percentage;
    QPushButton *pushButton;
    QPushButton *playAgainBtn;
    QLabel *congratulations;

    void setupUi(QDialog *WinDialog)
    {
        if (WinDialog->objectName().isEmpty())
            WinDialog->setObjectName(QStringLiteral("WinDialog"));
        WinDialog->resize(320, 240);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WinDialog->sizePolicy().hasHeightForWidth());
        WinDialog->setSizePolicy(sizePolicy);
        WinDialog->setMinimumSize(QSize(320, 240));
        WinDialog->setMaximumSize(QSize(320, 240));
        WinDialog->setModal(true);
        gridLayoutWidget = new QWidget(WinDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 321, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setContentsMargins(15, 0, 15, 0);
        time = new QLabel(gridLayoutWidget);
        time->setObjectName(QStringLiteral("time"));
        time->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(time, 1, 0, 1, 1);

        date = new QLabel(gridLayoutWidget);
        date->setObjectName(QStringLiteral("date"));
        date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(date, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);

        bestTime = new QLabel(gridLayoutWidget);
        bestTime->setObjectName(QStringLiteral("bestTime"));

        gridLayout->addWidget(bestTime, 2, 0, 1, 1);

        gamesPlayed = new QLabel(gridLayoutWidget);
        gamesPlayed->setObjectName(QStringLiteral("gamesPlayed"));

        gridLayout->addWidget(gamesPlayed, 3, 0, 1, 1);

        gamesWon = new QLabel(gridLayoutWidget);
        gamesWon->setObjectName(QStringLiteral("gamesWon"));

        gridLayout->addWidget(gamesWon, 4, 0, 1, 1);

        percentage = new QLabel(gridLayoutWidget);
        percentage->setObjectName(QStringLiteral("percentage"));

        gridLayout->addWidget(percentage, 4, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        playAgainBtn = new QPushButton(gridLayoutWidget);
        playAgainBtn->setObjectName(QStringLiteral("playAgainBtn"));
        sizePolicy1.setHeightForWidth(playAgainBtn->sizePolicy().hasHeightForWidth());
        playAgainBtn->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(playAgainBtn, 5, 2, 1, 1);

        congratulations = new QLabel(gridLayoutWidget);
        congratulations->setObjectName(QStringLiteral("congratulations"));
        congratulations->setAlignment(Qt::AlignCenter);
        congratulations->setWordWrap(true);

        gridLayout->addWidget(congratulations, 0, 0, 1, 3);

        gridLayout->setRowStretch(0, 4);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 2);
        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 3);
        QWidget::setTabOrder(playAgainBtn, pushButton);

        retranslateUi(WinDialog);

        QMetaObject::connectSlotsByName(WinDialog);
    } // setupUi

    void retranslateUi(QDialog *WinDialog)
    {
        WinDialog->setWindowTitle(QApplication::translate("WinDialog", "Game Won", 0));
        time->setText(QApplication::translate("WinDialog", "Time: ", 0));
        date->setText(QApplication::translate("WinDialog", "Date: ", 0));
        bestTime->setText(QApplication::translate("WinDialog", "Best time: ", 0));
        gamesPlayed->setText(QApplication::translate("WinDialog", "Games played: ", 0));
        gamesWon->setText(QApplication::translate("WinDialog", "Games won: ", 0));
        percentage->setText(QApplication::translate("WinDialog", "Percentage: ", 0));
        pushButton->setText(QApplication::translate("WinDialog", "Exit", 0));
        playAgainBtn->setText(QApplication::translate("WinDialog", "Play again", 0));
        congratulations->setText(QApplication::translate("WinDialog", "Congratulations, you  won the game!", 0));
    } // retranslateUi

};

namespace Ui {
    class WinDialog: public Ui_WinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDIALOG_H
