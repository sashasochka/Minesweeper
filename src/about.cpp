#include "about.h"
#include "ui_about.h"

#include <QDesktopWidget>

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About) {
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    adjustSize();
    setMaximumSize(size());
    setMinimumSize(size());
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
}

About::~About() noexcept {

}
