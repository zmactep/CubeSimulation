#include "environment.h"


Environment::Environment( Map* map )
{
  realMap = map;

  startFlag = false;

//  connect(this, SIGNAL(stateChanged()), this, SLOT(slot_nextStep()));
  start();
}

Environment::~Environment()
{
  deleteMap();
}

void Environment::simulationStep( void )
{
  static int i = 0;
  qDebug() << "Hello world! " << i++;
}

void Environment::run( void )
{
  while(1)
  {
    if(startFlag)
      simulationStep();

    emit stateChanged();

    msleep(1000/STEPS_PER_SECOND);
  }
}

// SLOTS
void Environment::slot_setStateChanged( void )
{
  emit stateChanged();
}

void Environment::slot_toggleStart( void )
{
  startFlag = !startFlag;
  if(startFlag)
    emit stateChanged();
}

void Environment::slot_nextStep( void )
{
  if(startFlag)
  {
    simulationStep();

    emit stateChanged();
  }
}
