#include "environment.h"


Environment::Environment( Map* map, AgentManagerFactory *facts )
{
  realMap = map;

  startFlag = false;


  if(facts == NULL)
    teams = NULL;
  else
  {
    teams = new AgentManager*[2];
    teams[0] = facts[0].createManagers(1);
    teams[1] = facts[1].createManagers(1);

    AgentFactory fact;
    teams[0]->createManager(map, &fact, 2);
    teams[1]->createManager(map, &fact, 2);
  }
//  connect(this, SIGNAL(stateChanged()), this, SLOT(slot_nextStep()));
  start();
}

Environment::~Environment()
{
  qDebug() << "Delete Environment";
  deleteMap();

  if(teams[0])
    delete teams[0];
  teams[0] = NULL;

  if(teams[1])
    delete teams[1];
  teams[1] = NULL;

  if(teams)
    delete teams;
  teams = NULL;

}

void Environment::simulationStep( void )
{
  static int i = 0;
  qDebug() << "Turn: " << i;

  teams[i]->setEnemy(getEnemyAgents(i));
  teams[i]->makeStep();

  i++;
  if(i > 1)
    i = 0;
}

QList<Point3D> Environment::exportAgents( int teamNum )
{
  QList<Point3D> list;
  QList<CubeBasic*> clist;

  clist.append(teams[teamNum]->getAgentsList());

  Point3D p;
  int coord[3];
  for( int i = 0; i < clist.length(); i++ )
  {
    realMap->getCubeCoord(clist.at(i), coord);
    p.x = coord[0];
    p.y = coord[1];
    p.z = coord[2];

    list.append(p);
  }

  return list;
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

QList<CubeBasic*> Environment::getEnemyAgents( int teamNumber )
{
  QList<CubeBasic*> list;

  if(teamNumber > 1)
    return list;

  AgentManager *current, *enemy;

  if(teamNumber)
  {
    current = teams[1];
    enemy = teams[0];
  }
  else
  {
    current = teams[0];
    enemy = teams[1];
  }

  int coord[3];

  for( int i = 0; i < current->getAgentsCount(); i++ )
  {
    current->getAgentCoords(i, coord);
    QList<CubeBasic*> tmp_list;
    tmp_list = enemy->getAgentsRoundPoint(coord[0], coord[1], coord[2]);

    for( int j = 0; j < tmp_list.length(); j++ )
      if(!list.contains(tmp_list.at(j)))
        list.append(tmp_list.at(j));
  }

  return list;
}
