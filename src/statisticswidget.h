#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QDialog>

class QDate;
class QTime;

class StatisticsWidget : public QDialog {
    Q_OBJECT
public:
    explicit StatisticsWidget(QWidget *parent = 0);
    void setBestTime(int msec);
    void setDate(QDate date);
    void setPercentage(float percentage);
    void setPlayedGames(int n);
    void setTime(QTime& time);
    void setWonGames(int n);

protected:
    ~StatisticsWidget();
};

#endif // STATISTICSWIDGET_H
