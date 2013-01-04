#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::About) {
  setAttribute(Qt::WA_DeleteOnClose);
  ui->setupUi(this);
}

About::~About() {
  delete ui;
}
