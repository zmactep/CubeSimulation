#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QDebug>
#include <QThread>
#include <QObject>
#include <QTimer>
#include "map.h"

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
#define STEPS_PER_SECOND 10

//!  Environment class.
/*!
  The main Simulation class. It has the real Map and agents managers.
  Gives the agent managers API for actions in the Map.
*/
class Environment : public QThread
{
  Q_OBJECT
private:
  //! Real map.
  /*!
    The real map, that has the information of all cubes state.
  */
  Map *realMap;

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

  //! Get start flag method.
  /*!
    \return true, if simulation started or false if not
  */
  inline bool isStarted( void )
  {
    return startFlag;
  }

  //! Simlation step method.
  /*!
    One step of simulation.
  */
  void simulationStep( void );

  //! Run method.
  /*!
    New thread working method.
  */
  void run( void );

signals:
  //! State changed signal.
  /*!
    This signal is sent, when something had happend in the Environment.
  */
  void stateChanged( void );

public slots:
  //! Force state change slot.
  /*!
    Force emits state change signal.
  */
  void slot_setStateChanged( void );

  //! Toggle Start Flag slot.
  /*!
    Toggles start flag, so the simulation may be paused or resumed.
  */
  void slot_toggleStart( void );

  //! Make next step slot.
  /*!
    One more simulation iteration.
  */
  void slot_nextStep( void );

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
