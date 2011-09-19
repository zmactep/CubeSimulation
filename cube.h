#ifndef CUBE_H
#define CUBE_H

#include <stdio.h>

//! Maximum infection.
/*!
  Maximum possible infection of one cube.
*/
#define MAX_INFECTION 10

//!  Cube class.
/*!
  Trivial building block of the map.
*/
class Cube
{
private:
  //! Infection value.
  /*!
    Current infection value of this cube.
  */
  int infection;

  //! Transparent flag.
  /*!
    If transparent flag is true, than any Agent can stay in it.
  */
  bool transparent;

public:
  //! Constructor.
  /*!
    Constructs object setting default values:
    no infection and positive transparent.
  */
  Cube()
  {
    infection = 0;
    transparent = true;
  }

  //! Set transparent method.
  /*!
    \param t a bool value of new transparent
    \return new transparent flag value
    \sa isTransparent()
  */
  inline bool setTransparent( bool t )
  {
    return transparent = t;
  }

  //! Set infection method.
  /*!
    \param i an integer value of new infection
    \return new infection value
    \sa incInfection(), decInfection() and getInfection()
  */
  inline int setInfection( int i )
  {
    if(i > MAX_INFECTION)
      i = MAX_INFECTION;
    return infection = i;
  }

  //! Infection increment method.
  /*!
    \return new infection value
    \sa setInfection(), decInfection() and getInfection()
  */
  inline int incInfection( void )
  {
    return infection < MAX_INFECTION ? ++infection : infection;
  }

  //! Infection decrement method.
  /*!
    \return new infection value
    \sa setInfection(), incInfection() and getInfection()
  */
  inline int decInfection( void )
  {
    return infection > 0 ? --infection : infection;
  }

  //! Get current infection value method.
  /*!
    \return current infection value
    \sa setInfection(), incInfection() and decInfection()
  */
  inline int getInfection( void )
  {
    return infection;
  }

  //! Get current transparent flag value method.
  /*!
    \return current transparent flag value
    \sa setTransparent()
  */
  inline bool isTransparent( void )
  {
    return transparent;
  }

  //! Cube assignment method.
  /*!
    \param c Cube to assign
    \return assigned Cube copy
  */
  inline Cube operator=(Cube c)
  {
    transparent = c.transparent;
    infection = c.infection;

    return *this;
  }
};

#endif // CUBE_H
