#include "cubesimulationwidget.h"

CubeSimulationWidget::CubeSimulationWidget(QWidget *parent)
  : QWidget(parent)
{
  QVBoxLayout *play = new QVBoxLayout(this);

  initEnvironment(5,5,5);

  wgtGL = new CubeSimulationView(this);
  wgtGL->loadEnvironment(env);

  connect(env, SIGNAL(stateChanged()), wgtGL, SLOT(updateGL()));

  QHBoxLayout *playControls = new QHBoxLayout(this);
  toggleButton = new QPushButton(tr("Start"), this);
  QPushButton *clearButtor = new QPushButton(tr("Clear"), this);
  QPushButton *exitButton = new QPushButton(tr("Exit"), this);

  connect(toggleButton, SIGNAL(clicked()), this, SLOT(slot_toggleSimulation()));
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
  env->terminate();
  if(env)
    delete env;
  env = NULL;
}

void CubeSimulationWidget::initEnvironment( int l, int w, int h )
{
  AgentManagerFactory facts[2];

  map = new Map(l,w,h);
  env = new Environment(map, facts);

  // Generate map here
  map->getCube(0,0,0)->setTransparent(false);

  map->getCube(0,1,0)->setTransparent(false);
  map->getCube(0,1,0)->setInfection(5);

  map->getCube(0,2,0)->setTransparent(false);
  map->getCube(0,2,0)->setInfection(10);
}

void CubeSimulationWidget::slot_toggleSimulation( void )
{
  env->slot_toggleStart();
  if(env->isStarted())
    toggleButton->setText("Pause");
  else
    toggleButton->setText("Start");
}
