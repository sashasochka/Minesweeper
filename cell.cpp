#include <QApplication>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>

#include "cell.h"
#include "field.h"

Cell::Cell(int y, int x, bool shown) :
  _y(y), _x(x),
  status(none),
  m_pressed(false),
  entered(false),
  opened(false),
  shown(shown),
  is_empty(true)
{
  setAttribute(Qt::WA_DeleteOnClose);
  setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  setMaximumSize(1000, 1000);
  setSpecialStyle(
    "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);");
}

bool Cell::empty()
{
  return is_empty;
}

void Cell::setBomb(bool val)
{
  is_empty = !val;
}

int Cell::x()
{
  return _x;
}

int Cell::y()
{
  return _y;
}

QPoint Cell::coords()
{
  return QPoint(_x, _y);
}

void Cell::open()
{
  if(!shown || opened) return;

  emit beforeOpened(x(), y());
  setPressed(false);

  if(empty()) {
    opened = true;
    disconnect(this);
    int neighbours = static_cast<Field*>(parentWidget())->
                     count_neighbour_bombs(coords());
    //setDown(true);

    if(neighbours) setText(QString::number(neighbours));

    //updateFontSize(size());
    QString color;

    switch(neighbours) {
    case 0:
      color = "black";
      break;
    case 1:
      color = "#33a";
      break;
    case 2:
      color = "green";
      break;
    case 3:
    case 7:
      color = "brown";
      break;
    case 4:
      color = "#33f";
      break;
    case 5:
    case 8:
      color = "brown";
      break;
    case 6:
      color = "cyan";
      break;
    }

    setSpecialStyle("#ddd", color, "font-weight:bold;");

    if(!neighbours) emit zeroBombNeighbours(coords());
  } else {
    emit defeat();
  }

  emit cellOpened();
}

void Cell::mouseReleaseEvent(QMouseEvent *event)
{
  if(opened || QApplication::widgetAt (QCursor::pos()) != this) return;

  if (event->button() == Qt::LeftButton) {
    if(!opened && status == none)
      open();
  } else if(event->button() == Qt::RightButton) {
    changeStatus();
  }
}

void Cell::mousePressEvent(QMouseEvent *ev)
{
  if(opened || status != none || ev->button() != Qt::LeftButton) return;

  setPressed(true);
}

void Cell::enterEvent(QEvent *)
{
  if(opened || status != none) return;

  setSpecialStyle(
    "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #09f, stop: 1 #eef);");
  entered = true;
}

void Cell::leaveEvent(QEvent *)
{
  if(opened || status != none) return;

  setSpecialStyle(
    "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);");
  entered = false;
}

void Cell::resizeEvent(QResizeEvent *event)
{
  updateFontSize(event->size());
}

void Cell::paintEvent(QPaintEvent *ev)
{
  QLabel::paintEvent(ev);

  if(status == flagged) {
    const int stick_x = width() / 1.6;
    const int stick_y = height() / 5;
    const int stick_height = height() / 1.7;
    const int stick_width = width() / 15;
    const int stick_end_y = stick_y + stick_height;
    const int flag_height = height() / 2.2;
    const int flag_width = width() / 2.6;
    QPolygon flag;
    flag << QPoint(stick_x - flag_width, stick_y + flag_height / 2);
    flag << QPoint(stick_x, stick_y);
    flag << QPoint(stick_x, stick_y + flag_height);
    QLine stick(stick_x, stick_y + stick_width / 2, stick_x, stick_end_y);
    QLine base(stick_x - flag_width * 0.5, stick_end_y, stick_x + flag_width * 0.3, stick_end_y);
    QPen stickpen;
    stickpen.setColor(Qt::white);
    stickpen.setWidth(stick_width);
    stickpen.setCapStyle(Qt::RoundCap);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(stickpen);
    painter.drawLine(stick);
    painter.drawLine(base);
    painter.setBrush(QBrush(Qt::red));
    painter.setPen(QPen(Qt::black));
    painter.drawPolygon(flag);
  }
}

void Cell::changeStatus()
{
  Settings settings;
  status++;
  status %= (settings.value("askMark", true).toBool() || status == asked + 1) ? 3 : 2;

  switch(status) {
  case none:
    setSpecialStyle(
      "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);");
    setText("");
    break;
  case flagged:
    setSpecialStyle(
          "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);", "red");
    break;
  case asked:
    setSpecialStyle(
          "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);", "yellow");
    setText("?");
    break;
  }
}

int Cell::getStatus()
{
  return status;
}

bool Cell::pressed() const
{
  return m_pressed;
}

void Cell::setPressed(bool arg)
{
  m_pressed = arg;

  if(arg)
    setSpecialStyle("QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #aaa, stop: 1 #fff)");
  else
    setSpecialStyle(
      "QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #06f, stop: 1 #ccf);");
}

void Cell::setSpecialStyle(QString background, QString color, QString add_qss)
{
  QString qss = "border:1px solid black;";

  if(!color.isEmpty()) qss.append("color: " + color + ";");

  if(!background.isEmpty()) qss.append("background: " + background + ";");

  qss.append(add_qss);
  setStyleSheet(qss);
}

void Cell::updateFontSize(const QSize& new_size)
{
  setFont(QFont("", qMin(new_size.height(), new_size.width()) / 1.7));
}


