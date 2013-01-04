#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QTime>
#include <QDate>

class StatisticsWidget : public QDialog
{
  Q_OBJECT
public:
  explicit StatisticsWidget(QWidget *parent = 0);

  void setTime(QTime& time);
  void setBestTime(int msec);
  void setPlayedGames(int n);
  void setWonGames(int n);
  void setDate(QDate date);
  void setPercentage(float percentage);
signals:

public slots:

};

#endif // STATISTICSWIDGET_H
