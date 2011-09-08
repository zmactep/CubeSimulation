#include <QtGui>
#include "cubesimulationwidget.h"

#include "level.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
//  CubeSimulationWidget w;

//  w.show();
  Level lvl;

  lvl.loadLevel("D:\\Projects\\COMMON\\TestText\\qt_parser.txt");

  qDebug() << "Ready";

  return a.exec();
}
