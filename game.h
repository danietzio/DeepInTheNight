#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "map.h"
#include <QScrollBar>
#include <QTimer>
#include <QObject>
#include <QWidget>
class game : public QGraphicsView {
public :
    game();
    QGraphicsScene *scene;
    map *_map;
    player *Player;
};



#endif // GAME_H
