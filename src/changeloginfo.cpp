#include "changeloginfo.h"
#include "ui_changeloginfo.h"

#include <QDesktopWidget>

ChangelogInfo::ChangelogInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangelogInfo) {
    ui->setupUi(this);
    adjustSize();
    setMaximumSize(size());
    setMinimumSize(size());
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());
}

ChangelogInfo::~ChangelogInfo() {

}
