#include "mainwindow.h"

#include "about.h"
#include "changeloginfo.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    , field(new Field(this))
    , ui(new Ui::MainWindow)
    , tmp_layout(new QVBoxLayout) {
    try {
        ui->setupUi(this);
        setWindowFlags((windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
        move(
            (QApplication::desktop()->width() - geometry().width()) / 2,
            (QApplication::desktop()->height() - geometry().height()) / 2.7
        );
        QPushButton* restartSmileButton = new QPushButton(QIcon(":/smile.jpg"), "");
        restartSmileButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        connect(field.data(), SIGNAL(needRestart()), SLOT(restart()));
        connect(restartSmileButton, SIGNAL(clicked()),     SLOT(restart()));
        tmp_layout->addWidget(restartSmileButton);
        tmp_layout->addWidget(field.data());
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

void MainWindow::on_actionExit_triggered() {
    exit(EXIT_SUCCESS);
}

void MainWindow::on_actionNew_Game_triggered() {
    restart();
}

void MainWindow::on_actionOptions_triggered() {
    field->optionsDialog();
}

void MainWindow::on_actionAbout_Minesweeper_triggered() {
    About* about = new About;
    about->show();
    about->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::restart() {
    static bool restarting = false;

    if (restarting) {
        return;
    }

    restarting = true;
    tmp_layout->removeWidget(field.data());
    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    field.reset(new Field(this));
    tmp_layout->addWidget(field.data());
    setFixedSize(prefSize());
    connect(field.data(), SIGNAL(needRestart()), SLOT(restart()));
    restarting = false;
}

void MainWindow::on_actionView_Help_triggered() {
    ChangelogInfo* changelog = new ChangelogInfo();
    changelog->show();
    changelog->setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::on_actionStastics_triggered() {
    field->statistics_dialog();
}


QSize MainWindow::prefSize() {
    return QSize(
               field->cellSize().width()  * field->cols + 20 + 3 * field->cols,
               field->cellSize().height() * field->rows + 63 + 3 * field->rows
    );
}

MainWindow::~MainWindow() {

}
