#ifndef AGENT_H
#define AGENT_H

#define MAX_HEALTH 100

#include "cubebasic.h"
#include "map.h"

//! Agent class.
/*!
  Agent is the citizen of the Environment. Depense on the team, it can be
  an infector or a healer.
*/
class Agent
{
private:
  //! Agent`s heals.
  /*!
    When the agent health is 0, it decativates.
  */
  int health;

  //! Agent`s plan.
  /*!
    Encoded Agent`s plan for the nex iteration.
  */
  unsigned char agentPlan;

  //! Agent`s CubeBasic.
  /*!
    A CubeBasic whitch the Agent is in.
  */
  CubeBasic *myCube;

public:
  //! Constructor.
  /*!
    Constructs full health Agent.
  */
  Agent()
  {
    health = MAX_HEALTH;
    agentPlan = 0;
  }

  //! Set plan method.
  /*!
    Sets the Agent`s plan for the next iteration.
    \param nPlan an encoded plan
  */
  inline void setPlan( unsigned char nPlan )
  {
    agentPlan = nPlan;
  }

  //! Get plan method.
  /*!
    Gets the Agent`s plan for the next iteration.
    \return an encoded plan
  */
  inline unsigned char getPlan( void )
  {
    return agentPlan;
  }

  //! Make plan method.
  /*!
    Make Agent`s plan for the next iteration.
    \param map pointer to Map where Agent lives
    \return an encoded plan
  */
  virtual unsigned char makePlan( Map* map )
  {
    agentPlan = 0;
    return 0;
  }

  //! Get health method.
  /*!
    Gets the Agent`s health.
    \return the health of the Agent
  */
  inline int getHealth( void )
  {
    return health;
  }

  //! Increment health method.
  /*!
    Increments Agent`s health for given value.
    \param value an incremention value
    \return the new health of the Agent
  */
  inline int incHealth( int value )
  {
    health += value;
    if(health > MAX_HEALTH)
      health = MAX_HEALTH;

    return health;
  }

  //! Decrement health method.
  /*!
    Decrements Agent`s health for given value.
    \param value a Decremention value
    \return the new health of the Agent
  */
  inline int decHealth( int value )
  {
    health -= value;
    if(health < 0)
      health = 0;

    return health;
  }
};

#endif // AGENT_H
