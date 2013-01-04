#ifndef FIELD_H
#define FIELD_H

#include <QGridLayout>
#include <QtCore>
#include <QWidget>

#include "cell.h"
#include "settings.h"

class Field : public QWidget
{
  Q_OBJECT
private:
  QGridLayout* f_layout;
  int mines;
  QVector<QVector<Cell*> > cells;
  void getSettings();
  Settings* settings;
  bool cells_are_filled;
public:
  int rows;
  int cols;
  bool askMark;
  bool won;

  QString lng;
  QTime time;
  QDate date;
  int bestBeginnerTime;
  int bestIntermediateTime;
  int bestAdvancedTime;
  int gamesPlayed;
  int gamesWon;

  explicit Field(QWidget *parent = 0);
  ~Field();
  int count_neighbour_bombs(QPoint pt);
signals:
  void needRestart();
  void needResize(int w, int h);
private slots:
  void fillCells(int, int);
  void testIfWin();
  void openNeighbours(QPoint);
  void changeSettings(int, int, int);
  void changeLanguage(QString);
  void askMarkAllow(bool);
  void defeatGame();
  void win();
public slots:
  void statistics_dialog();
  void optionsDialog();
  void saveSettings();
  void clearStatistics();
};

#endif // FIELD_H
