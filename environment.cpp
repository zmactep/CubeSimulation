#include "environment.h"


Environment::Environment( Map* map )
{
  realMap = map;

  startFlag = true;

  green = NULL;
  blue = NULL;

/*
  green = new AgentManager;
  blue = new AgentManager;

  green->setSubjMap(*realMap);
  blue->setSubjMap(*realMap);
*/
}

Environment::~Environment()
{
  deleteMap();

  if(green)
    delete green;
  green = NULL;

  if(blue)
    delete blue;
  blue = NULL;
}

void Environment::makeActions( void )
{
  static bool who = true;
  AgentManager *current;

  current = who ? green : blue;

  Map *tmpMap;
  int coord[3];

  for( int c = 0; c < 2; c++)
  {
    if(current)
      current->makeStrategy();

    for( int i = 0; i < current->getAgentsCount(); i++ )
    {
      if(!current->getAgentHealth(i))
        continue;

      if(!current->getAgentCoord(i, coord))
        continue;

      if(iWantTo(current->getAgentPlan(i), coord))
        current->approveLastAgentPlan(i);

      tmpMap = realMap->getSubMap(coord[0], coord[1], coord[2], VIEW_RADIUS);
      current->appendInfo(*tmpMap, coord[0], coord[1], coord[2], VIEW_RADIUS);

      delete tmpMap;
    }

    current = current == green ? blue : green;
  }

  who = !who;

  emit stateChanged();
}

// API
bool Environment::iWantTo( unsigned char action, int* coord )
{
  // Agent whants to do nothing. Let it do this! :)
  if(action == 0)
    return true;

  bool  dir_nord,           //
        dir_south,          //  w-1  w+1
        dir_west,           //    w n e   h-1
        dir_east,           //      s     h+1
        dir_up,             //  u l-1
        dir_down;           //  d l+1
  unsigned char act;

  dir_nord  = action & DIRECTION_NORD;
  dir_south = action & DIRECTION_SOUTH;
  dir_west  = action & DIRECTION_WEST;
  dir_east  = action & DIRECTION_EAST;
  dir_up    = action & DIRECTION_UP;
  dir_down  = action & DIRECTION_DOWN;

  act = action & ACTION_MASK;

  // TODO: Check action

  // TODO: Make action


  return true;
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
    makeActions();
}
