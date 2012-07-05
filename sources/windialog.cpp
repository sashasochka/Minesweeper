#include "windialog.h"
#include "ui_windialog.h"

WinDialog::WinDialog(QWidget *parent) :
    StatisticsWidget(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint |
                   Qt::WindowCloseButtonHint);
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_pushButton_clicked()
{
    exit(0);
}



void WinDialog::enableBestTimeCongratulations(bool enable)
{
    if(!enable) return;

    QLabel* label=findChild<QLabel*>("congratulations");
    label->setText(label->text()+"\n\n"+
                   tr("You have the fastest time for this difficulty level!"));
}

