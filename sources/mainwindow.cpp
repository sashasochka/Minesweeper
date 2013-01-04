#include <QtGui>
#include "mainwindow.h"
#include "field.h"
#include "about.h"
#include "changeloginfo.h"
#include "ui_mainwindow.h"

//windialog and defeat to make children from new base class named "StatisticWidget"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    try
    {


        ui->setupUi(this);




        move(
                    (QApplication::desktop()->width()-geometry().width())/2,
                    (QApplication::desktop()->height()-geometry().height())/2.7
                    );


        QPushButton* restartSmileButton=new QPushButton(QIcon(":/smile.jpg"),"");
        restartSmileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        field=new Field(this);


        connect(field,              SIGNAL(needRestart()), SLOT(restart()));
        connect(restartSmileButton, SIGNAL(clicked()),     SLOT(restart()));



        tmp_layout=new QVBoxLayout;
        tmp_layout->addWidget(restartSmileButton);
        tmp_layout->addWidget(field);
        tmp_layout->setAlignment(restartSmileButton, Qt::AlignHCenter);
        ui->centralWidget->setLayout(tmp_layout);
    }
    catch(...)
    {
        (new QMessageBox(QMessageBox::Critical, "Fatal error.",
                    "Unresolved exception. Contact to sasha.sochka@gmail.com")
                )->show();
        QApplication::exit(EXIT_FAILURE);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionNew_Game_triggered()
{
    restart();
}

void MainWindow::on_actionOptions_triggered()
{
    field->optionsDialog();
}

void MainWindow::on_actionAbout_Minesweeper_triggered()
{
    About* about=new About;
    about->show();
}

void MainWindow::restart()
{
    delete field;
    field=new Field(this);
    tmp_layout->addWidget(field);
    connect(field, SIGNAL(needRestart()), SLOT(restart()));
}

void MainWindow::on_actionView_Help_triggered()
{
    ChangelogInfo* changelog=new ChangelogInfo();

    changelog->show();
}

void MainWindow::on_actionStastics_triggered()
{
    field->statistics_dialog();
}
