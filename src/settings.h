#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSettings>

class Settings : public QSettings
{
  Q_OBJECT
private:
public:
  explicit Settings(QWidget *parent = 0);

signals:
public slots:

};
#endif // SETTINGS_H
