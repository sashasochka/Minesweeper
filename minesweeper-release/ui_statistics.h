/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created: Mon Jan 7 12:17:13 2013
**      by: Qt User Interface Compiler version 5.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *bestTime;
    QLabel *gamesPlayed;
    QLabel *percentage;
    QLabel *label_3;
    QLabel *gamesWon;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearBtn;
    QPushButton *pushButton;

    void setupUi(QWidget *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName(QStringLiteral("Statistics"));
        Statistics->resize(266, 180);
        gridLayoutWidget = new QWidget(Statistics);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 261, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(15, 10, 10, 10);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        bestTime = new QLabel(gridLayoutWidget);
        bestTime->setObjectName(QStringLiteral("bestTime"));

        gridLayout->addWidget(bestTime, 0, 1, 1, 1);

        gamesPlayed = new QLabel(gridLayoutWidget);
        gamesPlayed->setObjectName(QStringLiteral("gamesPlayed"));

        gridLayout->addWidget(gamesPlayed, 1, 1, 1, 1);

        percentage = new QLabel(gridLayoutWidget);
        percentage->setObjectName(QStringLiteral("percentage"));

        gridLayout->addWidget(percentage, 4, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        gamesWon = new QLabel(gridLayoutWidget);
        gamesWon->setObjectName(QStringLiteral("gamesWon"));

        gridLayout->addWidget(gamesWon, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearBtn = new QPushButton(gridLayoutWidget);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));

        horizontalLayout->addWidget(clearBtn);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);

        retranslateUi(Statistics);
        QObject::connect(pushButton, SIGNAL(released()), Statistics, SLOT(deleteLater()));
        QObject::connect(clearBtn, SIGNAL(released()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QWidget *Statistics)
    {
        Statistics->setWindowTitle(QApplication::translate("Statistics", "Statistics", 0));
        label->setText(QApplication::translate("Statistics", "Best time: ", 0));
        label_2->setText(QApplication::translate("Statistics", "Games played: ", 0));
        label_4->setText(QApplication::translate("Statistics", "Percentage: ", 0));
        bestTime->setText(QString());
        gamesPlayed->setText(QString());
        percentage->setText(QString());
        label_3->setText(QApplication::translate("Statistics", "Games won: ", 0));
        gamesWon->setText(QString());
        clearBtn->setText(QApplication::translate("Statistics", "Clear statistics", 0));
        pushButton->setText(QApplication::translate("Statistics", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
