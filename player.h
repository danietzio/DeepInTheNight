#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QSet>
class player : public QObject , public QGraphicsRectItem {
    Q_OBJECT
public:
    player(QGraphicsView *v);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int getx();
    int gety();

    QTimer *timer;
    QGraphicsView *view;

    bool barkhord = true;
    bool barkhord1 = true;
    bool mark_r = false;
    bool mark_u = false;
    bool mark_l = false;
    bool mark_d = false;
    bool mark_s = false;
    bool mark = true;
    bool left_pressed = false;
    bool right_pressed = false;
    int basey0 = 0;
    int y0 = 0;
    ~player();
protected slots:
    void move();
};


#endif // PLAYER_H
