#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QList>
#include "health.h"
#include <player.h>
#include <QGraphicsScene>
extern bool mark_ctrl_player;
extern bool health_enemy_decrease;
extern int x_player;
extern int y_player;
class enemy :  public QObject , public QGraphicsPixmapItem  {
    Q_OBJECT
public:
    enemy(QGraphicsScene *_Scene);
    int getx();
    int gety();
    void getPlayerCoordinate(qreal x,qreal y);
    void checkHealth();

private:
    QTimer *timer;
    QGraphicsView *view;

    QList<QGraphicsItem *> li;
    health *Health;
    QGraphicsScene *Scene;
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

    int basey0 = 0;
    int y0 = 0;
    static int speed;
    qreal x_pl,y_pl ;


    float calculateDistance();
    void moveright();
    void moveleft();
    bool checkCollision();
protected slots:
    void move();
};

#endif // ENEMY_H
