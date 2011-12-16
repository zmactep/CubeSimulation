#include <QtGui>
#include "cubesimulationwidget.h"

#include "map.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  AgentManagerFactory fact[2];
  CubeSimulationWidget w(":/maps/resources/map8.txt", fact, 2);
  w.resize(640, 480);
  w.show();

  return a.exec();
}
