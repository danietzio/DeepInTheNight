#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
class enemy :  public QObject , public QGraphicsRectItem  {
    Q_OBJECT
public:
    enemy();
    int getx();
    int gety();
    void getPlayerCoordinate(qreal x,qreal y);
    ~enemy();

private:
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
    bool suspection = false;
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
    static int speed;
    qreal x_pl,y_pl ;


    float calculateDistance();
    void moveright();
    void moveleft();
protected slots:
    void move();
};

#endif // ENEMY_H
