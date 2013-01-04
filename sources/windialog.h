#ifndef WINDIALOG_H
#define WINDIALOG_H

#include "statisticswidget.h"


namespace Ui {
    class WinDialog;
}

class WinDialog : public StatisticsWidget
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = 0);
    void enableBestTimeCongratulations(bool enable=true);
    ~WinDialog();

private slots:
    void on_pushButton_clicked();


private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_H
