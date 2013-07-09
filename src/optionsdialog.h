#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include "settings.h"

#include <QDialog>

class QLineEdit;
class QRadioButton;

#include <memory>

class OptionsDialog : public QDialog {
    Q_OBJECT
private:
    std::unique_ptr<Settings> settings;
    int cur_rows;
    int cur_cols;
    int cur_mines;

    QLineEdit* rows_edit;
    QLineEdit* cols_edit;
    QLineEdit* mines_edit;

    QRadioButton* beginRadio;
    QRadioButton* interRadio;
    QRadioButton* advRadio;
    QRadioButton* customRadio;
public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog() noexcept;

signals:
    void settings_changed(int rows, int cols, int mines);
    void language_changed(QString);
    void askMark_status_changed(bool enabled);

public slots:
    void setDisabledCustoms();
    void setEnabledCustoms();
    void ok();
};

#endif // OPTIONSDIALOG_H
