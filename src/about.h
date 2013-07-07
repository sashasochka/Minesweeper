#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

#include <memory>

namespace Ui {
class About;
}

class About final : public QWidget {
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About() noexcept;
private:
    std::unique_ptr<Ui::About> ui;
};

#endif // ABOUT_H
