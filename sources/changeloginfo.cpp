#include "changeloginfo.h"
#include "ui_changeloginfo.h"

ChangelogInfo::ChangelogInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangelogInfo)
{
    ui->setupUi(this);
    adjustSize();
    setMaximumSize(size());
    setMinimumSize(size());


}

ChangelogInfo::~ChangelogInfo()
{
    delete ui;
}
