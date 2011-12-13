#include <QtGui>
#include "cubesimulationwidget.h"

#include "map.h"
#include "fann/floatfann.h"
#include "fann/fann_cpp.h"

using namespace FANN;

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  CubeSimulationWidget w;
  w.resize(640, 480);
  w.show();

  return a.exec();
}
