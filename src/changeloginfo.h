#ifndef CHANGELOGINFO_H
#define CHANGELOGINFO_H

#include <QWidget>

#include <memory>

namespace Ui {
class ChangelogInfo;
}

class ChangelogInfo final : public QWidget {
    Q_OBJECT

public:
    explicit ChangelogInfo(QWidget *parent = 0);
    ~ChangelogInfo();
private:
    std::unique_ptr<Ui::ChangelogInfo> ui;
};

#endif // CHANGELOGINFO_H
