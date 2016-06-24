#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include "player.h"
#include <QScrollBar>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include "enemy.h"
#include <QMediaPlayer>
#include <health.h>
#include <score.h>
class game :  public QGraphicsView {
public :
    game();
    ~game();
    QGraphicsScene *scene;
    map *_map;
   enemy *Enemy;
    player *Player;
    //enemy *Enemy;
    int y0 = 0;
    QMediaPlayer  *media;
};



#endif // GAME_H
