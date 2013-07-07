#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

const int changeLanguageReturnCode = 2;

class Settings final : public QSettings {
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
};
#endif // SETTINGS_H
