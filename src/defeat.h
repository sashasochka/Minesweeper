#ifndef DEFEAT_H
#define DEFEAT_H

#include "statisticswidget.h"

#include <QScopedPointer>

namespace Ui {
class defeat;
}

class Defeat final : public StatisticsWidget {
    Q_OBJECT

public:
    explicit Defeat(QWidget *parent = 0);
    ~Defeat();

private slots:
    void on_exitButton_clicked();

private:
    QScopedPointer<Ui::defeat> ui;
};

#endif // DEFEAT_H
