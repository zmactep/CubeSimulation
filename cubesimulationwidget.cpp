#include "cubesimulationwidget.h"

CubeSimulationWidget::CubeSimulationWidget(QWidget *parent)
  : QWidget(parent)
{
  QVBoxLayout *play = new QVBoxLayout(this);

  initEnvironment(5,5,5);

  wgtGL = new CubeSimulationView(this);
  wgtGL->loadMap(map);

  connect(env, SIGNAL(stateChanged()), wgtGL, SLOT(updateGL()));

  QHBoxLayout *playControls = new QHBoxLayout(this);
  QPushButton *toggleButton = new QPushButton(tr("Start"), this);
  QPushButton *clearButtor = new QPushButton(tr("Clear"), this);
  QPushButton *exitButton = new QPushButton(tr("Exit"), this);

  connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

  playControls->addWidget(toggleButton);
  playControls->addWidget(clearButtor);
  playControls->addWidget(exitButton);

  play->addWidget(wgtGL);
  play->addLayout(playControls);

  setLayout(play);
}

CubeSimulationWidget::~CubeSimulationWidget()
{
  if(env)
    delete env;
  env = NULL;
}

void CubeSimulationWidget::initEnvironment( int l, int w, int h )
{
  map = new Map(l,w,h);
  env = new Environment(map);
}
