#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>
#include <QVariant>
#include <QWidget>
#include <QMap>

class Settings : QObject {
  Q_OBJECT
private:
  QMap<QString, QVariant> m;

public:
  explicit Settings(QWidget *parent = 0): QObject(parent){}

  QVariant value(QString key, QVariant def) {
    return def;
  }

  void setValue(QString key, QVariant value) {
    //m.insert(key, value);
  }

  void remove(QString key) {
    //m.remove(key);
  }

signals:

public slots:

};
#endif // SETTINGS_H
