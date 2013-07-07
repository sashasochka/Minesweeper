#ifndef MINECELL_H
#define MINECELL_H

#include <QLabel>

class QSize;

class Cell final : public QLabel {
    Q_OBJECT
    Q_PROPERTY(bool empty_prop READ empty)
    Q_PROPERTY(int  status READ getStatus)
    Q_PROPERTY(bool pressed READ pressed WRITE setPressed)

private:
    int _y;
    int _x;
    enum {none, flagged, asked};
    int status;
    bool m_pressed;
    bool entered;

public:
    bool opened;
    bool shown;
    bool is_empty;
    explicit Cell(int _x, int _y, bool shown = true, QWidget* parent = nullptr);
    bool empty() const noexcept ;
    void setBomb(bool val = true) noexcept;
    int x() const noexcept;
    int y() const noexcept;
    QPoint coords() const noexcept;
    int getStatus() const noexcept;
    void mouseReleaseEvent(QMouseEvent * event) noexcept;
    void mousePressEvent(QMouseEvent *ev) noexcept;
    void enterEvent(QEvent* ev) noexcept;
    void leaveEvent(QEvent* ev) noexcept;
    void resizeEvent(QResizeEvent * event) noexcept;
    void paintEvent(QPaintEvent*) noexcept;
    bool pressed() const noexcept;
    void setSpecialStyle(QString background = "", QString color = "", QString add_qss = "") noexcept;
    ~Cell() noexcept;
signals:
    void zeroBombNeighbours(QPoint);
    void cellOpened();
    void beforeOpened(int, int);
    void defeat();
public slots:
    void open() noexcept;
    void changeStatus() noexcept;
    void updateFontSize(const QSize&) noexcept;
    void setPressed(bool arg) noexcept;
    void setDefaultStyle(QString color = "") noexcept;
    void setHoveredStyle() noexcept;
    void setPressedStyle() noexcept;
    void setOpenedStyle(QString color) noexcept;
};

#endif // MINECELL_H
