#include "statisticswidget.h"

#include <QLabel>
#include <QCoreApplication>
#include <QTime>
#include <QDate>

StatisticsWidget::StatisticsWidget(QWidget *parent) :
    QDialog(parent) {
    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowCloseButtonHint);
}

void StatisticsWidget::setTime(QTime &time) {
    QLabel* label = findChild<QLabel*>("time");
    int secs = time.elapsed() / 1000;
    label->setText(
        label->text() + tr("%n second(s)", "", secs)
    );
}

void StatisticsWidget::setBestTime(int msec) {
    QLabel* label = findChild<QLabel*>("bestTime");
    int secs = msec / 1000;
    label->setText(label->text() + tr("%n second(s)", "", secs)                );
}

void StatisticsWidget::setPlayedGames(int n) {
    QLabel* label = findChild<QLabel*>("gamesPlayed");
    label->setText(label->text() +
                   QString::number(n));
}

void StatisticsWidget::setWonGames(int n) {
    QLabel* label = findChild<QLabel*>("gamesWon");
    label->setText(label->text() +
                   QString::number(n));
}

void StatisticsWidget::setDate(QDate date) {
    QLabel* label = findChild<QLabel*>("date");
    label->setText(label->text() +
                   date.toString("dd.MM.yyyy")
                  );
}

void StatisticsWidget::setPercentage(float percentage) {
    QLabel* label = findChild<QLabel*>("percentage");
    label->setText(label->text() +
                   QString::number(qRound(percentage)) +
                   "%");
}

StatisticsWidget::~StatisticsWidget() {
}
