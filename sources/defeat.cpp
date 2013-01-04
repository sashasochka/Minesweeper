#include "defeat.h"
#include "ui_defeat.h"

Defeat::Defeat(QWidget *parent) :
    StatisticsWidget(parent),
    ui(new Ui::defeat)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowCloseButtonHint);

}

Defeat::~Defeat()
{
    delete ui;
}

void Defeat::on_exitButton_clicked()
{
    emit exit(0);
}
