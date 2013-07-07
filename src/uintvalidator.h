#ifndef UINTVALIDATOR_H
#define UINTVALIDATOR_H

#include <QValidator>

class UIntValidator final : public QValidator {
    Q_OBJECT
public:
    explicit UIntValidator(QObject *parent = 0);
    State validate(QString &, int &) const;
};

#endif // UINTVALIDATOR_H
