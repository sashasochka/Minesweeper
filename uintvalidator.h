#ifndef UINTVALIDATOR_H
#define UINTVALIDATOR_H

#include <QValidator>

class UIntValidator : public QValidator {
  Q_OBJECT
public:
  explicit UIntValidator(QObject *parent = 0);
  virtual State validate(QString &, int &) const;

signals:

public slots:

};

#endif // UINTVALIDATOR_H
