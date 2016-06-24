#include "game.h"
#include "map.h"
#include "QRegion"
#include <QDebug>
#include "player.h"
bool exist_pl = false;
game::game()
{
    scene = new QGraphicsScene();
  //  Enemy = new enemy(scene);
    Player = new player(this,scene);
    _map = new map(this);

    this->setScene(scene);
    this->setMouseTracking(true);

    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();

   // scene->addItem(Enemy);
    scene->addItem(_map);
    scene->addItem(Player);
    scene->setBackgroundBrush(QBrush(QPixmap(":/new/img/F:/Qt/Poroje/backg1 (2).jpg")));
    scene->setSceneRect(0,0,25000,1024);
    //this->showFullScreen();


   //add music
    media = new QMediaPlayer();
    media->setMedia(QUrl("qrc:/new/Music/F:/Qt/Poroje/SPRITE/02. Intervention Of The Gods.mp3"));
    media->play();

}

game::~game()
{
    this->deleteLater();
}
