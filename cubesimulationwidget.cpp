#include "cubesimulationwidget.h"

CubeSimulationWidget::CubeSimulationWidget(QWidget *parent)
  : QWidget(parent)
{
  QVBoxLayout *play = new QVBoxLayout(this);

  wgtGL = new CubeSimulationView(this);


  QHBoxLayout *playControls = new QHBoxLayout(this);

  QPushButton *toggleButton = new QPushButton(tr("Start"), this);
  QPushButton *clearButtor = new QPushButton(tr("Clear"), this);
  QPushButton *exitButton = new QPushButton(tr("Exit"), this);

  playControls->addWidget(toggleButton);
  playControls->addWidget(clearButtor);
  playControls->addWidget(exitButton);


  play->addWidget(wgtGL);
  play->addLayout(playControls);

  setLayout(play);
}

CubeSimulationWidget::~CubeSimulationWidget()
{

}
