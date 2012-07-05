#ifndef DEFEAT_H
#define DEFEAT_H

#include <QDialog>
#include <QDate>
#include "statisticswidget.h"

namespace Ui {
    class defeat;
}

class Defeat : public StatisticsWidget
{
    Q_OBJECT

public:
    explicit Defeat(QWidget *parent = 0);

    ~Defeat();

private slots:
    void on_exitButton_clicked();

private:
    Ui::defeat *ui;
};

#endif // DEFEAT_H
