#include "map.h"

Map::Map()
{
  width = height = levels = 0;
  cubes = NULL;
  error = false;
}


Map::Map( int l, int w, int h )
{
  createMap(l, w, h);
}

Map::~Map()
{
  deleteMap();
}

Map Map::operator= (Map m)
{
  deleteMap();
  createMap(m.levels, m.width, m.height);

  for( int i = 0; i < levels; i++ )
    for( int j = 0; j < height; j++ )
      for( int k = 0; k < width; k++ )
      {
        cubes[i][j][k].setInfection(m.cubes[i][j][k].getInfection());
        cubes[i][j][k].setTransparent(m.cubes[i][j][k].isTransparent());
      }

  return *this;
}

bool Map::loadLevelMask( int l, bool** flags )
{
  if(l < 0 || l > levels)
    return false;

  for( int i = 0; i < height; i++ )
    for( int j = 0; j < width; j++ )
      cubes[l][i][j].setTransparent(flags[i][j]);

  return true;
}

Map* Map::getSubMap( int x, int y, int z, int rad )
{
  int coord[6];
  if(!getSubMapCoord(x,y,z,rad,coord))
    return NULL;

  // Set transparent and infection in new map
  Map *map = new Map(coord[5] - coord[4] + 1,
                     coord[3] - coord[2] + 1,
                     coord[1] - coord[0] + 1);

  for( int i = coord[4]; i < coord[5]; i++ )
    for( int j = coord[2]; j < coord[3]; j++ )
      for( int k = coord[0]; k < coord[1]; k++ )
      {
        map->cubes[i-coord[4]][j-coord[2]][k-coord[0]].setTransparent(
                                            cubes[i][j][k].isTransparent());
        map->cubes[i-coord[4]][j-coord[2]][k-coord[0]].setInfection(
                                            cubes[i][j][k].getInfection());
      }

  return map;
}

bool Map::appendSubMap( Map& app_map,
                               int x, int y, int z, int rad )
{
  int coord[6];
  if(!getSubMapCoord(x,y,z,rad,coord))
    return false;

  for( int i = 0; i < app_map.levels; i++ )
    for( int j = 0; j < app_map.height; j++ )
      for( int k = 0; k < app_map.width; k++ )
      {
        cubes[i+coord[4]][j+coord[2]][k+coord[0]].setTransparent(
                                       app_map.cubes[i][j][k].isTransparent());
        cubes[i+coord[4]][j+coord[2]][k+coord[0]].setInfection(
                                       app_map.cubes[i][j][k].getInfection());
      }

  return true;
}

bool Map::createMap( int l, int w, int h )
{
  width = w;
  height = h;
  levels = l;
  error = false;

  cubes = new Cube**[levels];
  if(!cubes)
  {
    error = true;
    return !error;
  }

  for( int i = 0; i < levels; i++ )
  {
    cubes[i] = new Cube*[height];
    if(!cubes[i])
    {
      error = true;
      return !error;
    }

    for( int j = 0; j < height; j++ )
    {
      cubes[i][j] = new Cube[width];
      if(!cubes[i][j])
      {
        error = true;
        return !error;
      }

      for( int k = 0; k < width; k++ )
      {
        cubes[i][j][k].setInfection(0);
        cubes[i][j][k].setTransparent(true);
      }
    }
  }

  return !error;
}

void Map::deleteMap()
{
  if(cubes == NULL)
    return;

  for( int i = 0; i < levels; i++ )
  {
    for( int j = 0; j < height; j++ )
    {
      if(cubes[i][j])
        delete[] cubes[i][j];
    }
    if(cubes[i])
      delete[] cubes[i];
  }

  delete[] cubes;
  cubes = NULL;
}

bool Map::getSubMapCoord( int x, int y, int z, int rad, int* coord)
{
  if(!checkCubeExists(x,y,z))
    return false;

  if(rad > MAX_VIEW_RADIUS)
    rad = MAX_VIEW_RADIUS;


  // Get distanse in each direction
  int dir_nord,           //
      dir_south,          //  w-1  w+1
      dir_west,           //    w n e   h-1
      dir_east,           //      s     h+1
      dir_up,             //  u l-1
      dir_down;           //  d l+1

  dir_nord = y - rad >= 0 ? rad : y;
  dir_south = y + rad <= height - 1 ? rad : (height - 1) - y;

  dir_west = x - rad >= 0 ? rad : x;
  dir_east = x + rad <= width - 1 ? rad : (width - 1) - x;

  dir_up = z - rad >= 0 ? rad : z;
  dir_down = z + rad <= levels - 1 ? rad : (levels - 1) - z;

  // Get size of new Map
  int w, h, l;

  w = dir_east + 1 + dir_west;
  h = dir_south + 1 + dir_nord;
  l = dir_down + 1 + dir_up;

  // Get 2 charactristic points of Map
  *coord = x - dir_west;
  *(coord + 1) = x + dir_east;

  *(coord + 2) = y - dir_nord;
  *(coord + 3) = y + dir_south;

  *(coord + 4) = z - dir_up;
  *(coord + 5) = z + dir_down;

  return true;
}
