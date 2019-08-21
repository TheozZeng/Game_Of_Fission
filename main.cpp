#include <QApplication>
#include "myitem.h"
#include "myview.h"
#include <QTime>
#include <QTimer>


int main(int argc, char * argv[]){
   QApplication app(argc,argv);
   qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
   QGraphicsScene scene;
   scene.setSceneRect(-200,-150,400,300);
   for(int i=0; i<5; i++){
       MyItem *item = new MyItem;
       item -> setColor(QColor(qrand() % 256, qrand() % 256,qrand() % 256));
       item -> setPos(i*50-90, -50);
       scene.addItem(item);
   }
   MyView view;
   view.setScene(&scene);
   view.setBackgroundBrush(QPixmap("../myview/background.jpg"));
   view.show();
   QTimer timer;
   QObject::connect(&timer,&QTimer::timeout,&scene,&QGraphicsScene::advance);
   timer.start(300);
   return app.exec();
}