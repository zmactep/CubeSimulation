#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include <QTimer>
#include "map.h"
#include "agentmanager.h"

#define DIRECTION_NORD  0x80
#define DIRECTION_SOUTH 0x40
#define DIRECTION_WEST  0x20
#define DIRECTION_EAST  0x10
#define DIRECTION_UP    0x08
#define DIRECTION_DOWN  0x04

#define ACTION_MASK     0x03

#define ACTION_KILL     0x03
#define ACTION_INFECT   0x02
#define ACTION_HEAL     0x01
#define ACTION_GO       0x00


// Params for agent`s simulation
#define VIEW_RADIUS     3
#define ONE_HIT_FORCE   20

//!  Environment class.
/*!
  The main Simulation class. It has the real Map and agents managers.
  Gives the agent managers API for actions in the Map.
*/
class Environment : public QObject
{
  Q_OBJECT
private:
  //! Real map.
  /*!
    The real map, that has the information of all cubes state.
  */
  Map *realMap;

  //! Agent Managers.
  /*!
    Two teams, that are fighting in the Environment.
  */
  AgentManager *green, *blue;

  //! Live flag.
  /*!
    If this flag is true, the simulation is working, else paused.
  */
  bool startFlag;

public:
  //!  Map setup constructor.
  /*!
    Creates Environment with given Map. Creates two teams.
    \param map a Map that will be used by Environment
    \sa Environment(), setMap() and changeMap()
  */
  Environment( Map* map = NULL );

  //!  Destructor.
  /*!
    Deletes all used memory when the object`s live ends.
    \sa deleteMap()
  */
  ~Environment();

  //!  Map setup method.
  /*!
    Sets Environment Map as given.
    \param map a Map that will be used by Environment
    \return pointer to the new Map
    \sa Environment(), Environment(Map *map) and changeMap()
  */
  inline Map* setMap( Map* map )
  {
    realMap = map;
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

  //! One itertion actions method.
  /*!
    Makes all the agents of the both teams to do something. If one team goes
    first, than in next iteration another will.
  */
  void makeActions( void );

  //! A try of Agent to do something method.
  /*!
    \param action an action, that the Agent whants to do
    \param coord coordinates of the Agent, that whants to do something
    \return true if the Agent can do this, or false if it cannot
  */
  bool iWantTo( unsigned char, int* );


signals:
  //! State changed signal.
  /*!
    This signal is sent, when something had happend in the Environment.
  */
  void stateChanged( void );

public slots:
  //! Force state change slot
  /*!
    Force emits state change signal.
  */
  void slot_setStateChanged( void );

  //! Toggle Start Flag slot
  /*!
    Toggles start flag, so the simulation may be paused or resumed.
  */
  void slot_toggleStart( void );

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
