//!  Environment class.
/*!
  The main Simulation class. It has the real Map and agents managers.
  Gives the agent managers API for actions in the Map.
*/

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "map.h"

class Environment
{
private:
  //! Real map.
  /*!
    The real map, that has the information of all cubes state.
  */
  Map *realMap;

public:
  Environment()
  {
    realMap = NULL;
  }

  Environment( Map* map ) : realMap(map)
  {
  }

  ~Environment()
  {
    deleteMap();
  }

  inline Map* setMap( Map* map ) : realMap(map)
  {
    return realMap;
  }

  inline Map* changeMap( Map* map )
  {
    Map* oldMap = realMap;
    realMap = map;

    return oldMap;
  }

  // API


public slots:
  // API Slots


private:
  inline void deleteMap( void )
  {
    if(realMap)
      delete realMap;

    realMap = NULL;
  }
};

#endif // ENVIRONMENT_H
