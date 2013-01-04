#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QLineEdit>
#include <QRadioButton>
#include <QComboBox>

class OptionsDialog : public QDialog {
  Q_OBJECT
private:
  QSettings* settings;

  QLineEdit* rows_edit;
  QLineEdit* cols_edit;
  QLineEdit* mines_edit;

  QRadioButton* beginRadio;
  QRadioButton* interRadio;
  QRadioButton* advRadio;
  QRadioButton* customRadio;

  QComboBox* lng_combo;

  int cur_rows;
  int cur_cols;
  int cur_mines;

public:
  explicit OptionsDialog(QWidget *parent = 0);

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
