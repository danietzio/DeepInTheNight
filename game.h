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
class game : public QGraphicsView {
public :
    game();
    QGraphicsScene *scene;
    map *_map;
    player *Player;
    enemy *Enemy;
    int y0 = 0;
};



#endif // GAME_H
