#ifndef CHANGELOGINFO_H
#define CHANGELOGINFO_H

#include <QScopedPointer>
#include <QWidget>

namespace Ui {
class ChangelogInfo;
}

class ChangelogInfo final : public QWidget {
    Q_OBJECT

public:
    explicit ChangelogInfo(QWidget *parent = 0);
    ~ChangelogInfo();
private:
    QScopedPointer<Ui::ChangelogInfo> ui;
};

#endif // CHANGELOGINFO_H
