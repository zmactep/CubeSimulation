#include <QtGui>
#include "cubesimulationwidget.h"

#include "cube.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CubeSimulationWidget w;
  w.show();

  return a.exec();
}
