#include "settings.h"


int Settings::rows;

Settings::Settings(QObject *parent) :
    QObject(parent)
{
}

void Settings::load()
{
    Settings::rows=9;
}
