#include "map.h"
map::map(QGraphicsView *v)
{

   QVector<QPoint> list;
 list<< QPoint(0,1024)      << QPoint(34800,1024)   << QPoint(34744,740)
     << QPoint(32720,770)   << QPoint(32650,805)    << QPoint(32590,820)
     << QPoint(32490,811)   << QPoint(32410,820)    << QPoint(32350,798)
     << QPoint(32341,797)   << QPoint(32296,780)    << QPoint(31020,770)
     << QPoint(30750,823)   << QPoint(30500,805)    << QPoint(30288,796)
     << QPoint(30210,800)   << QPoint(30180,820)    << QPoint(30110,823)
     << QPoint(30045,796)   << QPoint(30010,797)    << QPoint(29970,807)
     << QPoint(29912,825)   << QPoint(29880,823)    << QPoint(29510,860)
     << QPoint(28950,853)   << QPoint(28850,710)    << QPoint(28710,700)
     << QPoint(28540,720)   << QPoint(28350,780)    << QPoint(28045,737)
     << QPoint(26000,820)   << QPoint(25970,780)    << QPoint(25000,830)
     << QPoint(24890,840)   << QPoint(24800,860)
     << QPoint(24700,860)   << QPoint(24400,880)    << QPoint(24300,880)
     << QPoint(24110,863)   << QPoint(24000,885)    << QPoint(23900,880)
     << QPoint(23800,870)   << QPoint(23700,850)    << QPoint(23600,830)
     << QPoint(23400,820)   << QPoint(23370,817)    << QPoint(23300,815)
     << QPoint(23200,800)   << QPoint(23120,810)    << QPoint(23000,800)
     << QPoint(22950,790)   << QPoint(22880,760)    << QPoint(22700,725)
     << QPoint(22600,720)   << QPoint(22290,755)    << QPoint(22200,765)
     << QPoint(22100,780)   << QPoint(21900,795)    << QPoint(21800,791)
     << QPoint(21500,785)   << QPoint(21200,800)    << QPoint(21100,810)
     << QPoint(20950,815)   << QPoint(20910,805)    << QPoint(20890,815)
     << QPoint(20840,805)   << QPoint(20810,825)    << QPoint(20450,880)
     << QPoint(20350,880)   << QPoint(20180,900)    << QPoint(20050,930)
     << QPoint(19970,930)   << QPoint(19830,870)    << QPoint(19740,870)
     << QPoint(19680,870)   << QPoint(19660,860)    << QPoint(19620,870)
     << QPoint(19600,860)   << QPoint(19480,910)    << QPoint(19445,910)
     << QPoint(19400,900)   << QPoint(19250,900)    << QPoint(19200,900)
     << QPoint(19150,920)   << QPoint(19000,930)    << QPoint(18810,950)
     << QPoint(18790,940)   << QPoint(18600,965)    << QPoint(17500,950)
     << QPoint(17200,960)   << QPoint(17100,950)    << QPoint(16100,955)
     << QPoint(15900,940)   << QPoint(15400,950)    << QPoint(15100,960)
     << QPoint(14900,950)   << QPoint(14700,920)    << QPoint(14360,910)
     << QPoint(14200,900)   << QPoint(14050,860)    << QPoint(13800,840)
     << QPoint(13690,850)   << QPoint(13560,790)    << QPoint(13540,800)
     << QPoint(13500,795)   << QPoint(13440,810)    << QPoint(13420,810)
     << QPoint(13280,800)   << QPoint(13050,850)    << QPoint(12500,770)
     << QPoint(12270,800)   << QPoint(11950,800)    << QPoint(11585,830)
     << QPoint(11520,800)   << QPoint(11320,805)    << QPoint(11180,800)
     << QPoint(11075,830)   << QPoint(10750,835)    << QPoint(10500,860)
     << QPoint(10300,840)   << QPoint(9980,820)     << QPoint(9700,820)
     << QPoint(9550,800)    << QPoint(9365,800)     << QPoint(9300,790)
     << QPoint(9230,800)    << QPoint(9090,760)     << QPoint(8950,770)
     << QPoint(8800,760)    << QPoint(8650,795)     << QPoint(8300,750)
     << QPoint(8000,740)    << QPoint(7680,750)     << QPoint(7630,765)
     << QPoint(7550,820)    << QPoint(7500,900)
     << QPoint(7450,1000)   << QPoint(7430,1024)    << QPoint(7120,1024)
     << QPoint(7085,685)    << QPoint(6910,695)     << QPoint(6930,1024)
     << QPoint(6520,1024)   << QPoint(6520,800)     << QPoint(6390,800)
     << QPoint(6370,1024)   << QPoint(6270,1024)    << QPoint(6300,710)
     << QPoint(6115,695)    << QPoint(6050,1024)    << QPoint(5750,1024)
     << QPoint(5650,500)    << QPoint(5280,550)     << QPoint(5330,1024)
     << QPoint(5320,1024)   << QPoint(4955,1024)    << QPoint(4955,950)
     << QPoint(4940,800)    << QPoint(4920,590)     << QPoint(4740,610)
     << QPoint(4750,1024)   << QPoint(4550,1024)    << QPoint(4500,1000)
     << QPoint(4445,900)    << QPoint(4435,800)     << QPoint(4430,690)
     << QPoint(3500,690)    << QPoint(3330,750)     << QPoint(3150,750)
     << QPoint(3000,730)    << QPoint(2900,750)     << QPoint(2500,740)
     << QPoint(2000,750)    << QPoint(1600,740)     << QPoint(1400,750)
     << QPoint(1200,740)    << QPoint(1100,750)     << QPoint(1000,770)
     << QPoint(800,770)     << QPoint(500,690)      << QPoint(0,690);

   QPolygonF poly(list);

   //Set Polygons One
   setPolygon(poly);


   //Set Brush
   setBrush(QBrush(QColor(Qt::red)));

   //check Collision
   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(isCollision()));
   timer->start(1);
   view = v;
}

