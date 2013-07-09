#include "optionsdialog.h"

#include "settings.h"
#include "uintvalidator.h"

#include <QApplication>
#include <QCheckBox>
#include <QDesktopWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QSettings>

#include <QComboBox>

OptionsDialog::OptionsDialog(QWidget *parent) :
    QDialog(parent)
    , settings{new Settings}
    , cur_rows{settings->value("rows", 9).toInt()}
    , cur_cols{settings->value("cols", 9).toInt()}
    , cur_mines{settings->value("mines", 10).toInt()}
    , rows_edit{new QLineEdit{QString::number(cur_rows)}}
    , cols_edit{new QLineEdit{QString::number(cur_cols)}}
    , mines_edit{new QLineEdit{QString::number(cur_mines)}}
    , beginRadio{new QRadioButton{
        tr("Beginner \n(9x9, 10 bombs)")
    }}
    , interRadio {new QRadioButton{
        tr("Intermediate \n(16x16, 40 bombs)")
    }}
    , advRadio {new QRadioButton{
            tr("Advanced \n(16x30, 99 bombs)")
    }}
    , customRadio {new QRadioButton{tr("Custom")}}
{

    QLabel* rows_label{new QLabel{tr("Rows:")}};
    QLabel* cols_label{new QLabel{tr("Cols:")}};
    QLabel* mines_label{new QLabel{tr("Mines:")}};
    QLabel* lng_label{new QLabel{tr("Language:")}};
    QCheckBox* askMarkBox{new QCheckBox{tr("Allow question marks")}};
    QPushButton* okBtn{new QPushButton{tr("OK")}};
    QGroupBox* group{new QGroupBox{tr("Difficulty")}};
    QGridLayout* sizeGrid{new QGridLayout};
    QGridLayout* custom_layout{new QGridLayout};
    QVBoxLayout* layout{new QVBoxLayout};
    QHBoxLayout* lng_layout{new QHBoxLayout};
    QComboBox* lng_combo{new QComboBox};

    setWindowTitle(tr("Options"));
    setWindowFlags(Qt::CustomizeWindowHint |
    Qt::WindowCloseButtonHint);
    setModal(true);
    QSize size(320, 320);
    setMinimumSize(size);
    setMaximumSize(size);
    setGeometry(QApplication::desktop()->width() / 3,
    QApplication::desktop()->height() / 3,
    size.rwidth(),
    size.rheight());

    setDisabledCustoms();
    lng_combo->setMaximumWidth(40);
    QStringList lng_list;
    lng_list << "en" << "uk";
    lng_combo->addItems(lng_list);
    lng_combo->setCurrentIndex(
        lng_combo->findText(settings->value("language").toString())
    );
    askMarkBox->setChecked(settings->value("askMark", true).toBool());
    okBtn->setMaximumWidth(100);
    sizeGrid->addWidget(beginRadio, 0, 0);
    sizeGrid->addWidget(interRadio, 1, 0);
    sizeGrid->addWidget(advRadio, 2, 0);
    group->setLayout(sizeGrid);
    custom_layout->addWidget(customRadio, 0, 0, 1, 2);
    custom_layout->addWidget(rows_label, 1, 0);
    custom_layout->addWidget(rows_edit, 1, 1);
    custom_layout->addWidget(cols_label, 2, 0);
    custom_layout->addWidget(cols_edit, 2, 1);
    custom_layout->addWidget(mines_label, 3, 0);
    custom_layout->addWidget(mines_edit, 3, 1);
    sizeGrid->addLayout(custom_layout, 0, 1, 0, 3);
    lng_layout->addWidget(lng_label);
    lng_layout->addWidget(lng_combo);
    lng_layout->addStretch(5);
    layout->setMargin(20);
    layout->addWidget(group);
    layout->addLayout(lng_layout);
    layout->addWidget(askMarkBox);
    layout->addWidget(okBtn);
    setLayout(layout);
    rows_edit->setValidator(new UIntValidator);
    cols_edit->setValidator(new UIntValidator);
    mines_edit->setValidator(new UIntValidator);
    connect(beginRadio, SIGNAL(clicked()), SLOT(setDisabledCustoms()));
    connect(interRadio, SIGNAL(clicked()), SLOT(setDisabledCustoms()));
    connect(advRadio, SIGNAL(clicked()), SLOT(setDisabledCustoms()));
    connect(customRadio, SIGNAL(clicked()), SLOT(setEnabledCustoms ()));
    connect(lng_combo, SIGNAL(currentIndexChanged(QString)),
    SIGNAL(language_changed(QString)));
    connect(askMarkBox,  SIGNAL(toggled(bool)), SIGNAL(askMark_status_changed(bool)));
    connect(okBtn, SIGNAL(clicked()), SLOT(ok()));

    if (cur_rows == 9 && cur_cols == 9 && cur_mines == 10) {
        beginRadio->click();
    } else if(cur_rows == 16) {
        if (cur_cols == 16 && cur_mines == 40) {
            interRadio->click();
        } else if(cur_cols == 30 && cur_mines == 99) {
            advRadio->click();
        }
    } else {
        customRadio->click();
    }

    show();
}

void OptionsDialog::setDisabledCustoms() {
    rows_edit->setEnabled(false);
    cols_edit->setEnabled(false);
    mines_edit->setEnabled(false);
}

void OptionsDialog::setEnabledCustoms() {
    rows_edit->setEnabled(true);
    cols_edit->setEnabled(true);
    mines_edit->setEnabled(true);
}

void OptionsDialog::ok() {
    int new_rows, new_cols, new_mines;

    if(beginRadio->isChecked()) {
        new_rows = new_cols = 9;
        new_mines = 10;
    } else if(interRadio->isChecked()) {
        new_rows = new_cols = 16;
        new_mines = 40;
    } else if (advRadio->isChecked()) {
        new_rows = 16;
        new_cols = 30;
        new_mines = 99;
    } else {
        new_rows = rows_edit->text().toInt();
        new_cols = cols_edit->text().toInt();
        new_mines = mines_edit->text().toInt();

        bool data_correct{false};

        QString errorTitle{"Error"};
        QString errorText;
        if(!new_rows) {
            errorText = "Number of rows must be above zero";
        } else if(!new_cols) {
            errorText = "Number of columns must be above zero";
        } else if(!new_mines) {
            errorText = "Number of mines must be above zero";
        } else if(new_mines > new_rows * new_cols * 0.8) {
            errorText = "Number of mines must be below number of cells";
        } else if(new_cols >= 50) {
            errorText = "Number of columns is too big";
        } else if(new_rows >= 50) {
            errorText = "Number of rows is too big";
        } else {
            data_correct = true;
        }
        if (!data_correct) {
            QScopedPointer<QMessageBox> mb{new QMessageBox{
                    QMessageBox::Warning, errorTitle, errorText
                }};
            mb->exec();
            return;
        }
    }

    if(new_rows != cur_rows || new_cols != cur_cols || new_mines != cur_mines) {
        emit settings_changed(new_rows, new_cols, new_mines);
    }

    deleteLater();
}

OptionsDialog::~OptionsDialog() noexcept {

}

