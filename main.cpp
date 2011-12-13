#include <QtGui>
#include "cubesimulationwidget.h"

#include "map.h"
#include "fann/floatfann.h"
#include "fann/fann_cpp.h"

using namespace FANN;

int main(int argc, char *argv[])
{

  neural_net* net;
  QApplication a(argc, argv);
  CubeSimulationWidget w;
  w.resize(640, 480);
  w.show();
/*
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
*/
  return a.exec();
}
