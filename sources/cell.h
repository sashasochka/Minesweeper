#ifndef MINECELL_H
#define MINECELL_H

#include <QtGui>

class Cell : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(bool empty_prop READ empty)
    Q_PROPERTY(int status READ getStatus)
    Q_PROPERTY(bool pressed READ pressed WRITE setPressed)

private:
    int _y;
    int _x;
    enum{none, flagged, asked};
    int status;
    bool m_pressed;
    bool entered;
public:
    bool opened;
    bool shown;
    explicit Cell(int _x, int _y, bool shown=true);
    bool empty();
    void setBomb(bool val=true);
    bool is_empty;
    int x();
    int y();
    QPoint coords();
    int getStatus();
    void mouseReleaseEvent ( QMouseEvent * event );
    void mousePressEvent(QMouseEvent *ev);
    void enterEvent(QEvent* ev);
    void leaveEvent(QEvent* ev);
    void resizeEvent ( QResizeEvent * event ) ;
    void paintEvent(QPaintEvent *);
    bool pressed() const;
    void setSpecialStyle( QString background="", QString color="", QString add_qss="");

signals:
    void zeroBombNeighbours(QPoint);
    void cellOpened();
    void beforeOpened(int,int);
    void defeat();
public slots:
    void open();
    void changeStatus();
    void updateFontSize();
    void setPressed(bool arg);
};

#endif // MINECELL_H
