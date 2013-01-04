#include "settings.h"

Settings::Settings(QWidget *parent):
  QSettings("Minesweeper", "Sochka Oleksandr", parent)
{
}