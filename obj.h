#ifndef OBJ_H
#define OBJ_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QSet>
#include <QImage>
#include <QObject>
#include <QDebug>
#include <QColor>
#include <QBrush>
#include <QtMath>
#define PI 3.14159265
#include <QScrollBar>
#include <QGraphicsView>
#include "game.h"
#include <QImage>
#include <QMainWindow>
#include <QWidget>
#include <QEvent>
class obj : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT
public:
    obj(QGraphicsView *v);


    int getx();
    int gety();

    QTimer *timer;
    QGraphicsView *view;
    QImage *sprite;
    QPixmap *player_sprite;
    bool barkhord = true;
    bool barkhord1 = true;
    bool mark_r = false;
    bool mark_shift = false;
    bool mark_ctrl = false;
    bool mark_u = false;
    bool mark_l = false;
    bool mark_d = false;
    bool mark_s = false;
    bool mark = true;
    bool left_pressed = false;
    bool right_pressed = false;
    bool right_realesed = false;
    bool left_realesed = false;
    bool turn_left = true;
    bool turn_right = true;
    bool going_up = false;
    bool going_down = false;
    bool ctrl_released = true;
    int basey0 = 0;
    int y0 = 0;
    int flap_sprite_x = 0;
    static int speed;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    ~obj();
};

#endif // OBJ_H
