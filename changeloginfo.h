#ifndef CHANGELOGINFO_H
#define CHANGELOGINFO_H

#include <QWidget>

namespace Ui
{
class ChangelogInfo;
}

class ChangelogInfo : public QWidget
{
  Q_OBJECT

public:
  explicit ChangelogInfo(QWidget *parent = 0);
  ~ChangelogInfo();

private:
  Ui::ChangelogInfo *ui;
};

#endif // CHANGELOGINFO_H
