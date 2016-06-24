#ifndef ENEMY2_H
#define ENEMY2_H
#include <QGraphicsPixmapItem>
#include <health.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsLineItem>
#include <QPainter>
extern int x_player;
extern int y_player;
class enemy2 : public QObject , public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enemy2(QGraphicsScene *scene,qreal x2,qreal y2);
    QGraphicsScene *Scene;
    health *Health;
    QTimer *timer;
    void moveright();
    void moveleft();
    void movedown();
    void moveup();
    float calculateDistance();

    bool barkhord = true;
    bool barkhord1 = true;
    bool mark_r = false;
    bool mark_u = false;
    bool mark_l = false;
    bool mark_d = false;
    bool mark_s = false;
    bool mark = true;
    bool suspection = false;
    bool left_pressed = false;
    bool right_pressed = false;
    bool right_realesed = false;
    bool left_realesed = false;
    bool turn_left = false;
    bool turn_right = false;
    bool going_up = false;
    bool going_down = false;
    bool ctrl_released = true;
    bool collied_with_player = false;
    static int speed;
    qreal x_pl,y_pl ;
    qreal x_2,y_2;
protected slots:
    void move();
};

#endif // ENEMY2_H
