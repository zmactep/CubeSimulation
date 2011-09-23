#ifndef CUBESIMULATIONVIEW_H
#define CUBESIMULATIONVIEW_H

#include <QtOpenGL>
#include "map.h"

//!  CubeSimulationView class.
/*!
  A window, where the simulation is showed using OpenGL.
*/
class CubeSimulationView : public QGLWidget
{
  Q_OBJECT
private:
  //!  Simulation Map.
  /*!
    The real Map of the Simulation.
  */
  Map *viewMap;

// Some test stuff
/*
  QTimer timer;
  QTime startTime;
  bool isRotateTimer;
*/

public:
  //! Constructor.
  /*!
    Installs parent object, if it exists.
    \param parent a parent object
  */
  explicit CubeSimulationView(QWidget *parent = 0);


  //! Load Map method.
  /*!
    Loads a Map to show.
    \param map a Map to show
  */
  inline void loadMap( Map *map )
  {
    viewMap = map;
  }

signals:

// Another test stuff
/*
public slots:
  void slot_installRotateTimer();
*/

protected:
  //! Init start OpenGL params method.
  /*!
    Installs background color, and enables some GL features.
  */
  void initializeGL( void );

  //! Reshape window listener method.
  /*!
    Changes view parametres, when the size of the window was changed.
    \param w new width of the window
    \param h new height of the window
  */
  void resizeGL( int, int );

  //! Drawing method.
  /*!
    Draws current scene. Redraws on updateGL() slot calling.
  */
  void paintGL( void );

private:
  //! Draw view Map method.
  /*!
    Draws all the cubes of the view Map. Cube color depends on
    it`s infection and transparent.
  */
  void drawMap( void );

  //! Draw one Cube method.
  /*!
    Draws the Cube of the Map with the given coordinates. Cube color depends on
    it`s infection and transparent.
    \param x an integer x-coordinate of drawing Cube
    \param y an integer y-coordinate of drawing Cube
    \param z an integer z-coordinate of drawing Cube
  */
  void drawCube( int, int, int );


  //! Draw one cube shape.
  /*!
    Draws one cube shape withthe given color and blending.
    Cube size is 1x1x1. Cube center is in 0x0x0.
    \param r a red part of shape`s color
    \param g a green part of shape`s color
    \param b a blue part of shape`s color
    \param alpha a blending value of the shape
  */
  void drawBlendCube( float r = 1.0,
                      float g = 1.0,
                      float b = 1.0,
                      float alpha = 0.5 );

  //! Draw axes method.
  /*!
    Draws three axes on the scene.
  */
  void drawAxes( void );
};

#endif // CUBESIMULATIONVIEW_H
