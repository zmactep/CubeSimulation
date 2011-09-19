#ifndef MAP_H
#define MAP_H

#include <stdio.h>

#include "cube.h"

#define max(x,y) (x) > (y) ? (x) : (y)
#define min(x,y) (x) < (y) ? (x) : (y)

#define DIRECTION_NORD  0
#define DIRECTION_SOUTH 1
#define DIRECTION_WEST  2
#define DIRECTION_EAST  3
#define DIRECTION_UP    4
#define DIRECTION_DOWN  5

//!  Maximum view radius.
/*!
  The maximum distanse from the look point to generate new map.
*/
#define MAX_VIEW_RADIUS 5

//!  Map class.
/*!
  The map of the Simulation. May be real and subjective.
  Has lots of methods towork with it and syncronise maps.
*/
class Map
{
private:
  //!  Cubes of the map.
  /*!
    3D array of Cubes, that make the map.
  */
  Cube ***cubes;

  //!  Dimensions of the map.
  /*!
    Number of map levels and dimensions of this levels.
  */
  int levels,
      width,
      height;

  //!  Error flag.
  /*!
    This simple flag is true if something wrong in this map.
  */
  bool error;

public:
  //!  Default constructor.
  /*!
    Creates empty map.
    \sa Map(int, int, int), operator =()
  */
  Map();

  //! Dimensions-based contructor.
  /*!
    Creates the map with given dimensions.
    \param l an integer number of map`s levels
    \param w an integer width of each level
    \param h an integer height of each level
    Sets up error flag if something wrong with memory.
    \sa Map(), createMap() and operator =()
  */
  Map( int, int, int );

  //! Destructor
  /*!
    Deletes all used memory when the object`s live ends.
    \sa deleteMap()
  */
  ~Map();

  //! Map assignment method.
  /*!
    \param m Map to assign
    \return assigned Map copy
    \sa Map(), Map(int, int, int) and ~Map()
  */
  Map operator= (Map);

  //! Load one level method.
  /*!
    \param l an integer number of loading level
    \param flags 2D array of transparent flags, must be height*width size
    \return true if there were not any errors and
            false if somesing wrong had happend
  */
  bool loadLevelMask( int, bool** );

  //! Get submap method.
  /*!
    Gets submap with the given radius around the given reference point.
    \param x an integer x-coordinate of reference Cube
    \param y an integer y-coordinate of reference Cube
    \param z an integer z-coordinate of reference Cube
    \param rad an integer radius
    \return pointer to submap
    \sa appendSubMap()
  */
  Map* getSubMap( int, int, int, int );

  //! Append submap method.
  /*!
    Appends submap to current map by given reference point and radius around it.
    \param app_map a submap to append
    \param x an integer x-coordinate of reference Cube
    \param y an integer y-coordinate of reference Cube
    \param z an integer z-coordinate of reference Cube
    \param rad an integer radius
    \return true if there were not any errors and
            false if somesing wrong had happend
    \sa getSubMap()
  */
  bool appendSubMap( Map&, int, int, int, int );

  //! Check error method.
  /*!
    \return current error state
    \sa setError()
  */
  inline bool isError( void )
  {
    return error;
  }

  //! Set error method.
  /*!
    \return a copy of current map with true error flag
    \sa isError()
  */
  inline Map setError( void )
  {
    Map map = *this;

    map.error = true;
    return map;
  }

  //! Get levels count method.
  /*!
    \return a number of map`s levels
    \sa getHeight(), getWidth()
  */
  inline int getLevels( void )
  {
    return levels;
  }

  //! Get height method.
  /*!
    \return a map`s height dimension
    \sa getLevels(), getWidth()
  */
  inline int getHeight( void )
  {
    return height;
  }

  //! Get width method.
  /*!
    \return a map`s width dimension
    \sa getLevels(), getHeight()
  */
  inline int getWidth( void )
  {
    return width;
  }

  // Cube operations

  //! Check Cube transparent method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return the transparent flag value of given Cube
  */
  inline bool isTransparent( int x, int y, int z )
  {
    if(!checkCubeExists(x,y,z))
      return false;

    return cubes[z][y][x].isTransparent();
  }

  //! Get Cube infection value method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return an infection value of given Cube
  */
  inline int getInfection( int x, int y, int z )
  {
    if(!checkCubeExists(x,y,z))
      return -1;

    return cubes[z][y][x].getInfection();
  }

  //! Cube infection increment method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return a new infection value of given Cube
  */
  inline int incInfection( int x, int y, int z )
  {
    if(!checkCubeExists(x,y,z))
      return -1;

    return cubes[z][y][x].incInfection();
  }

  //! Cube infection decrement value method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return a new infection value of given Cube
  */
  inline int decInfection( int x, int y, int z )
  {
    if(!checkCubeExists(x,y,z))
      return -1;

    return cubes[z][y][x].decInfection();
  }

  //! Get Cube pointer method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return pointer to the given Cube
  */
  inline Cube* getCube( int x, int y, int z )
  {
    if(!checkCubeExists(x,y,z))
      return NULL;

    return &cubes[z][y][x];
  }

private:
  //! Create map method.
  /*!
    Creates the map with given dimensions.
    \param l an integer number of map`s levels
    \param w an integer width of each level
    \param h an integer height of each level
    Sets up error flag if something wrong with memory.
    \sa Map(), Map(int, int, int), ~Map(), and operator =()
  */
  bool createMap( int, int, int );

  //! Delete map method.
  /*!
    Deletes all used memory of the Map.
    \sa Map(), Map(int, int, int), ~Map() and operator =()
  */
  void deleteMap();

  //! Get submap coordinates method.
  /*!
    Gets submap with the given radius around
    the given reference point coordinates.
    \param l an integer level number of reference point
    \param x an integer width-coordinate of reference point
    \param y an integer height-coordinate of reference point
    \param rad an integer radius
    \param coord an integer array to put values to, the length must be 6
    \return true if there were not any errors and
            false if somesing wrong had happend
    \sa getSubMap(), appendSubMap()
  */
  bool getSubMapCoord( int, int, int, int, int* );


  //! Check coordinates method.
  /*!
    \param x an integer x-coordinate of Cube
    \param y an integer y-coordinate of Cube
    \param z an integer z-coordinate of Cube
    \return true if coordinates are in the Map and
            false if not
  */
  inline bool checkCubeExists( int x, int y, int z )
  {
    if(z < 0 || z > levels ||
       y < 0 || y > height ||
       x < 0 || x > width)
      return false;

    return true;
  }
};

#endif // MAP_H
