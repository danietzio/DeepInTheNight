#include "game.h"
#include "map.h"
#include "QRegion"
#include <QDebug>
#include "player.h"
bool exist_pl = false;
game::game()
{
    scene = new QGraphicsScene();
    this->setScene(scene);
    scene->setSceneRect(0,0,25000,1024);
    Enemy = new enemy();
    Player = new player(this,Enemy);
    exist_pl = true;
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();
    _map = new map(this);
    scene->addItem(Enemy);
    scene->addItem(_map);
    scene->addItem(Player);
    scene->setBackgroundBrush(QBrush(QPixmap(":/new/img/F:/Qt/Poroje/backg1 (2).jpg")));

    this->setMouseTracking(true);
    //this->showFullScreen();


   //add music
   // media = new QMediaPlayer();
   // media->setMedia(QUrl("qrc:/new/Music/F:/Qt/Poroje/Back to the Future 3 - Sega Genesis - Stage 1.mp3"));
   // media->play();
}
