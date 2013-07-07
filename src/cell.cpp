#include "cell.h"

#include "field.h"
#include "settings.h"

#include <QApplication>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>

Cell::Cell(int y, int x, bool shown, QWidget *parent) :
    QLabel(parent),
    _y(y), _x(x),
    status(none),
    m_pressed(false),
    entered(false),
    opened(false),
    shown(shown),
    is_empty(true) {
    if (!shown) {
        hide();
        return;
    }

    setAttribute(Qt::WA_DeleteOnClose);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setMaximumSize(1000, 1000);
    setDefaultStyle();
    setFixedSize(30, 30);
}

bool Cell::empty() const noexcept {
    return is_empty;
}

void Cell::setBomb(bool val) noexcept {
    is_empty = !val;
}

int Cell::x() const noexcept {
    return _x;
}

int Cell::y() const noexcept {
    return _y;
}

QPoint Cell::coords() const noexcept {
    return QPoint(_x, _y);
}

void Cell::open() noexcept {
    if(!shown || opened) {
        return;
    }

    emit beforeOpened(x(), y());
    setPressed(false);

    if(empty()) {
        opened = true;
        disconnect(this);
        int neighbours = dynamic_cast<Field*>(parentWidget())->
           count_neighbour_bombs(coords());
        // setDown(true);

        if(neighbours) {
            setText(QString::number(neighbours));
        }

        // updateFontSize(size());

        QVector<QString> color_for_neighbours = {
            "black",
            "#33a",
            "green",
            "brown",
            "#33f",
            "brown",
            "cyan",
            "brown",
            "brown"
        };

        setOpenedStyle(color_for_neighbours[neighbours]);

        if(!neighbours) {
            emit zeroBombNeighbours(coords());
        }
    } else {
        emit defeat();
    }

    emit cellOpened();
}

void Cell::mouseReleaseEvent(QMouseEvent *event) noexcept {
    if(opened || QApplication::widgetAt (QCursor::pos()) != this) {
        return;
    }

    if (event->button() == Qt::LeftButton) {
        if(!opened && status == none) {
            open();
        }
    } else if(event->button() == Qt::RightButton) {
        changeStatus();
    }
}

void Cell::mousePressEvent(QMouseEvent *ev) noexcept {
    if(opened || status != none || ev->button() != Qt::LeftButton) {
        return;
    }

    setPressed(true);
}

void Cell::enterEvent(QEvent *) noexcept {
    if(opened || status != none) {
        return;
    }

    setHoveredStyle();
    entered = true;
}

void Cell::leaveEvent(QEvent *) noexcept {
    if(opened || status != none) {
        return;
    }

    setDefaultStyle();
    entered = false;
}

void Cell::resizeEvent(QResizeEvent *event) noexcept {
    updateFontSize(event->size());
}

void Cell::paintEvent(QPaintEvent *ev) noexcept {
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

void Cell::changeStatus() noexcept {
    Settings settings;
    status++;
    status %= (settings.value("askMark", true).toBool() || status == asked + 1) ? 3 : 2;
    setText("");

    switch(status) {
    case none:
        setDefaultStyle();
        break;
    case flagged:
        setDefaultStyle("red");
        break;
    case asked:
        setDefaultStyle("yellow");
        setText("?");
        break;
    }
}

int Cell::getStatus() const noexcept {
    return status;
}

bool Cell::pressed() const noexcept {
    return m_pressed;
}

void Cell::setPressed(bool arg) noexcept {
    m_pressed = arg;
    arg ? setPressedStyle() : setDefaultStyle();
}

void Cell::setSpecialStyle(QString background, QString color, QString add_qss) noexcept {
    setIndent(0);
    QString qss =  "border:1px solid black;";

    if(!color.isEmpty()) {
        qss.append("color: " + color + ";");
    }

    if(!background.isEmpty()) {
        qss.append("background: " + background + ";");
    }

    qss.append(add_qss);
    setStyleSheet(qss);
}

void Cell::updateFontSize(const QSize& new_size) noexcept {
    setFont(QFont("", qMin(new_size.height(), new_size.width()) / 2));
}

void Cell::setDefaultStyle(QString color) noexcept {
    setFrameStyle(Panel | Raised);
    setSpecialStyle("#aaa", color);
}

void Cell::setHoveredStyle() noexcept {
    setSpecialStyle("yellow");
}

void Cell::setPressedStyle() noexcept {
    setSpecialStyle("green");
}

void Cell::setOpenedStyle(QString color) noexcept {
    setSpecialStyle("#ddd", color);
}

Cell::~Cell() noexcept {

}

