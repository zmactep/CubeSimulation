#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "map.h"

//!  Environment class.
/*!
  The main Simulation class. It has the real Map and agents managers.
  Gives the agent managers API for actions in the Map.
*/
class Environment
{
private:
  //! Real map.
  /*!
    The real map, that has the information of all cubes state.
  */
  Map *realMap;

public:
  //!  Default constructor.
  /*!
    Creates Environment with empty Map.
    \sa Environment(Map *map), setMap() and changeMap()
  */
  Environment()
  {
    realMap = NULL;
  }

  //!  Map setup constructor.
  /*!
    Creates Environment with given Map.
    \param map a Map that will be used by Environment
    \sa Environment(), setMap() and changeMap()
  */
  Environment( Map* map ) : realMap(map)
  {
  }

  //!  Destructor.
  /*!
    Deletes all used memory when the object`s live ends.
    \sa deleteMap()
  */
  ~Environment()
  {
    deleteMap();
  }

  //!  Map setup method.
  /*!
    Sets Environment Map as given.
    \param map a Map that will be used by Environment
    \return pointer to the new Map
    \sa Environment(), Environment(Map *map) and changeMap()
  */
  inline Map* setMap( Map* map ) : realMap(map)
  {
    return realMap;
  }

  //!  Map change method.
  /*!
    Change Environment Map as given and returns old map.
    \param map a Map that will be used by Environment
    \return pointer to the old Map
    \sa Environment(), Environment(Map *map) and setMap()
  */
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
  //!  Delete current Map method.
  /*!
    Deletes used Map.
    \sa ~Environment()
  */
  inline void deleteMap( void )
  {
    if(realMap)
      delete realMap;

    realMap = NULL;
  }
};

#endif // ENVIRONMENT_H
