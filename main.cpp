#include <QtGui>
#include "cubesimulationwidget.h"

#include "map.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CubeSimulationWidget w;
  w.show();

  Map map(12,12,12);
  qDebug() << map.getHeight() <<
              " " <<
              map.getWidth() <<
              " " <<
              map.getLevels();

  Map *map2;
  map2 = map.getSubMap(2,2,2,4);

  qDebug() << map2->getHeight() <<
              " " <<
              map2->getWidth() <<
              " " <<
              map2->getLevels();

  delete map2;

  return a.exec();
}
