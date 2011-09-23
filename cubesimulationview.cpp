#include "cubesimulationview.h"

CubeSimulationView::CubeSimulationView(QWidget *parent) :
  QGLWidget(parent)
{
  viewMap = NULL;

/*
  isRotateTimer = false;
*/
}

/*
void CubeSimulationView::slot_installRotateTimer( void )
{
  startTime.start();
  connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
  timer.start(40);

  isRotateTimer = true;
}
*/

void CubeSimulationView::initializeGL( void )
{
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_RGBA);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
}

void CubeSimulationView::resizeGL( int w, int h )
{
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (double)w / h, 1, 500);
  gluLookAt(0, 5, -15,
            0, 0, 0,
            0, 1, 0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void CubeSimulationView::paintGL( void )
{
/*
  unsigned long int sceneTime = startTime.elapsed();
*/

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

/*
    if(isRotateTimer)
      glRotatef(0.1*sceneTime, 0, 1, 0);
*/

    glScalef(1.5,1.5,1.5);
    drawMap();

  glPopMatrix();
}

void CubeSimulationView::drawMap( void )
{
  if(!viewMap || viewMap->isError())
    return;

  for( int y = 0; y < viewMap->getLevels(); y++ )
    for( int z = 0; z < viewMap->getHeight(); z++ )
      for( int x = 0; x < viewMap->getWidth(); x++ )
        drawCube(x, y, z);
}

void CubeSimulationView::drawCube( int x, int y, int z )
{
  if(!viewMap || viewMap->isError())
    return;

  int infection = viewMap->getInfection(x,y,z);
  bool transparent = viewMap->isTransparent(x,y,z);

  glPushMatrix();

    float x_dist, y_dist, z_dist;

    x_dist = x - viewMap->getWidth() / 2.0 + 0.5;
    y_dist = y - viewMap->getLevels() / 2.0 + 0.5;
    z_dist = z - viewMap->getHeight() / 2.0 + 0.5;

    float inf_color = infection ? 0.5 + 0.05*infection : 0;

    glTranslatef(x_dist*1.1, y_dist*1.1, z_dist*1.1);
    drawBlendCube(transparent + inf_color, transparent, transparent);

  glPopMatrix();
}

void CubeSimulationView::drawBlendCube( float r, float g, float b, float alpha )
{
  // FACES

  glColor4f(r, g, b, alpha);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBegin(GL_QUADS);
    // Bottom
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    // Top
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // Front
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);

    // Back
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    // Left
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    // Right
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
  glEnd();

  glDisable(GL_BLEND);

  // LINES

  glColor3f(0,0,0);

  glBegin(GL_LINES);
    glVertex3f(-0.51, -0.51, -0.51);
    glVertex3f(0.51, -0.51, -0.51);

    glVertex3f(0.51, -0.51, -0.51);
    glVertex3f(0.51, -0.51, 0.51);

    glVertex3f(0.51, -0.51, 0.51);
    glVertex3f(-0.51, -0.51, 0.51);

    glVertex3f(-0.51, -0.51, 0.51);
    glVertex3f(-0.51, -0.51, -0.51);


    glVertex3f(-0.51, 0.51, -0.51);
    glVertex3f(0.51, 0.51, -0.51);

    glVertex3f(0.51, 0.51, -0.51);
    glVertex3f(0.51, 0.51, 0.51);

    glVertex3f(0.51, 0.51, 0.51);
    glVertex3f(-0.51, 0.51, 0.51);

    glVertex3f(-0.51, 0.51, 0.51);
    glVertex3f(-0.51, 0.51, -0.51);


    glVertex3f(-0.51, -0.51, -0.51);
    glVertex3f(-0.51, 0.51, -0.51);

    glVertex3f(0.51, -0.51, -0.51);
    glVertex3f(0.51, 0.51, -0.51);

    glVertex3f(0.51, -0.51, 0.51);
    glVertex3f(0.51, 0.51, 0.51);

    glVertex3f(-0.51, -0.51, 0.51);
    glVertex3f(-0.51, 0.51, 0.51);
  glEnd();
}

void CubeSimulationView::drawAxes( void )
{
  glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-10, 0, 0);
    glVertex3f(10, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -10, 0);
    glVertex3f(0, 10, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -10);
    glVertex3f(0, 0, 10);
  glEnd();
}

// SLOTS
