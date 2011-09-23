#ifndef AGENT_H
#define AGENT_H

#define MAX_HEALTH 100

//! Agent class.
/*!
  Agent is the citizen of the Environment. Depense on the team, it can be
  an infector or a healer.
*/
class Agent
{
private:
  //! Agent`s coordinates.
  /*!
    The position of the Agent in real Map.
  */
  int x, y, z;

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

public:
  //! Constructor.
  /*!
    Constructs full health Agent in the given point of the Map.
    \param _x an integer x-coordinate of Agent`s Cube
    \param _y an integer y-coordinate of Agent`s Cube
    \param _z an integer z-coordinate of Agent`s Cube
  */
  Agent( int _x = 0, int _y = 0, int _z = 0) :x(_x), y(_y), z(_z)
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

  //! Move agent method.
  /*!
    Moves Agent to the given point.
    \param nx an integer x-coordinate of destination Cube
    \param ny an integer y-coordinate of destination Cube
    \param nz an integer z-coordinate of destination Cube
  */
  inline void moveTo( int nx, int ny, int nz )
  {
    x = nx;
    y = ny;
    z = nz;
  }

  //! Get x-coord method.
  /*!
    Gets the x-coord of the Agent.
    \return integer x-coordinate of Agent`s Cube
  */
  inline int getX( void )
  {
    return x;
  }

  //! Get y-coord method.
  /*!
    Gets the y-coord of the Agent.
    \return integer y-coordinate of Agent`s Cube
  */
  inline int getY( void )
  {
    return y;
  }

  //! Get z-coord method.
  /*!
    Gets the z-coord of the Agent.
    \return integer z-coordinate of Agent`s Cube
  */
  inline int getZ( void )
  {
    return z;
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
