#include "mainwindow.h"

#include <QDesktopWidget>
#include <QPushButton>
#include <QMessageBox>

#include "about.h"
#include "changeloginfo.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  try {
    ui->setupUi(this);
    setWindowFlags((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    move(
      (QApplication::desktop()->width() - geometry().width()) / 2,
      (QApplication::desktop()->height() - geometry().height()) / 2.7
    );
    QPushButton* restartSmileButton = new QPushButton(QIcon(":/smile.jpg"), "");
    restartSmileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    field = new Field(this);
    connect(field,              SIGNAL(needRestart()), SLOT(restart()));
    connect(restartSmileButton, SIGNAL(clicked()),     SLOT(restart()));
    tmp_layout = new QVBoxLayout;
    tmp_layout->addWidget(restartSmileButton);
    tmp_layout->addWidget(field);
    tmp_layout->setAlignment(restartSmileButton, Qt::AlignHCenter);
    ui->centralWidget->setLayout(tmp_layout);
    setFixedSize(prefSize());
  } catch(...) {
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
  About* about = new About;
  about->show();
}

void MainWindow::restart()
{
  tmp_layout->removeWidget(field);
  delete field;
  setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
  field = new Field(this);
  tmp_layout->addWidget(field);
  setFixedSize(prefSize());
  connect(field, SIGNAL(needRestart()), SLOT(restart()));
}

void MainWindow::on_actionView_Help_triggered()
{
  ChangelogInfo* changelog = new ChangelogInfo();
  changelog->show();
}

void MainWindow::on_actionStastics_triggered()
{
  field->statistics_dialog();
}


QSize MainWindow::prefSize()
{
  return QSize(
        field->cellSize().width()  * field->cols + 20 + 3 * field->cols,
        field->cellSize().height() * field->rows + 63 + 3 * field->rows);
}
