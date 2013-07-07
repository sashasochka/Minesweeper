#include "settings.h"
#include <QWidget>

Settings::Settings(QWidget *parent):
    QSettings("Minesweeper", "Sochka Oleksandr", parent) {
}
