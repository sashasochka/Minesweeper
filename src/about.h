#ifndef ABOUT_H
#define ABOUT_H

#include <QScopedPointer>
#include <QWidget>

namespace Ui {
class About;
}

class About final : public QWidget {
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About() noexcept;
private:
    QScopedPointer<Ui::About> ui;
};

#endif // ABOUT_H
