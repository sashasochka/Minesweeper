#include "uintvalidator.h"

UIntValidator::UIntValidator(QObject *parent) :
    QValidator(parent)
{
}

QValidator::State UIntValidator::validate(QString &str , int &) const
{
    if(str.toUInt() || str.isEmpty() || str=="0" ) return Acceptable;
    return Invalid;
}
