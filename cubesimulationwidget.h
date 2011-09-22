#ifndef CUBESIMULATIONWIDGET_H
#define CUBESIMULATIONWIDGET_H

#include <QtGui>

#include "cubesimulationview.h"

class CubeSimulationWidget : public QWidget
{
  Q_OBJECT

private:
  CubeSimulationView *wgtGL;

public:
  CubeSimulationWidget(QWidget *parent = 0);
  ~CubeSimulationWidget();
};

#endif // CUBESIMULATIONWIDGET_H
