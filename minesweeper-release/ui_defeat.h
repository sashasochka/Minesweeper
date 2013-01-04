/********************************************************************************
** Form generated from reading UI file 'defeat.ui'
**
** Created: Sat Jan 5 00:39:46 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFEAT_H
#define UI_DEFEAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_defeat
{
public:
    QFrame *gridFrame;
    QGridLayout *gridLayout;
    QPushButton *exitButton;
    QPushButton *restartButton;
    QPushButton *play_againBtn;
    QVBoxLayout *verticalLayout;
    QLabel *time;
    QLabel *bestTime;
    QLabel *gamesPlayed;
    QLabel *gamesWon;
    QVBoxLayout *verticalLayout_2;
    QLabel *date;
    QLabel *percentage;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *defeat)
    {
        if (defeat->objectName().isEmpty())
            defeat->setObjectName(QStringLiteral("defeat"));
        defeat->setWindowModality(Qt::NonModal);
        defeat->resize(474, 209);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(defeat->sizePolicy().hasHeightForWidth());
        defeat->setSizePolicy(sizePolicy);
        defeat->setMinimumSize(QSize(474, 209));
        defeat->setMaximumSize(QSize(474, 209));
        defeat->setContextMenuPolicy(Qt::NoContextMenu);
        defeat->setSizeGripEnabled(false);
        defeat->setModal(true);
        gridFrame = new QFrame(defeat);
        gridFrame->setObjectName(QStringLiteral("gridFrame"));
        gridFrame->setGeometry(QRect(0, 0, 471, 211));
        gridLayout = new QGridLayout(gridFrame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 1, -1, -1);
        exitButton = new QPushButton(gridFrame);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        gridLayout->addWidget(exitButton, 4, 0, 1, 1);

        restartButton = new QPushButton(gridFrame);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setEnabled(false);

        gridLayout->addWidget(restartButton, 4, 1, 1, 2);

        play_againBtn = new QPushButton(gridFrame);
        play_againBtn->setObjectName(QStringLiteral("play_againBtn"));

        gridLayout->addWidget(play_againBtn, 4, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        time = new QLabel(gridFrame);
        time->setObjectName(QStringLiteral("time"));

        verticalLayout->addWidget(time);

        bestTime = new QLabel(gridFrame);
        bestTime->setObjectName(QStringLiteral("bestTime"));

        verticalLayout->addWidget(bestTime);

        gamesPlayed = new QLabel(gridFrame);
        gamesPlayed->setObjectName(QStringLiteral("gamesPlayed"));

        verticalLayout->addWidget(gamesPlayed);

        gamesWon = new QLabel(gridFrame);
        gamesWon->setObjectName(QStringLiteral("gamesWon"));

        verticalLayout->addWidget(gamesWon);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        date = new QLabel(gridFrame);
        date->setObjectName(QStringLiteral("date"));
        date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(date);

        percentage = new QLabel(gridFrame);
        percentage->setObjectName(QStringLiteral("percentage"));
        percentage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(percentage);


        gridLayout->addLayout(verticalLayout_2, 2, 1, 1, 2);

        label_3 = new QLabel(gridFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 4);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(3, 1);
        QWidget::setTabOrder(play_againBtn, restartButton);
        QWidget::setTabOrder(restartButton, exitButton);

        retranslateUi(defeat);

        QMetaObject::connectSlotsByName(defeat);
    } // setupUi

    void retranslateUi(QDialog *defeat)
    {
        defeat->setWindowTitle(QApplication::translate("defeat", "Game Lost", 0));
        exitButton->setText(QApplication::translate("defeat", "Exit", 0));
        restartButton->setText(QApplication::translate("defeat", "Restart", 0));
        play_againBtn->setText(QApplication::translate("defeat", "Play again", 0));
        time->setText(QApplication::translate("defeat", "Time: ", 0));
        bestTime->setText(QApplication::translate("defeat", "Best time: ", 0));
        gamesPlayed->setText(QApplication::translate("defeat", "Games played: ", 0));
        gamesWon->setText(QApplication::translate("defeat", "Games won: ", 0));
        date->setText(QApplication::translate("defeat", "Date: ", 0));
        percentage->setText(QApplication::translate("defeat", "Percentage: ", 0));
        label_3->setText(QApplication::translate("defeat", "Sorry, you lost this game. Better luck next time!", 0));
    } // retranslateUi

};

namespace Ui {
    class defeat: public Ui_defeat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFEAT_H
