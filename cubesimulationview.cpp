#include "cubesimulationview.h"

CubeSimulationView::CubeSimulationView(QWidget *parent) :
  QGLWidget(parent)
{
  startTime.start();
}

void CubeSimulationView::initializeGL( void )
{
  glClearColor(0.0, 1.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_RGBA);
}

void CubeSimulationView::resizeGL(int w, int h)
{
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (double)w / h, 1, 500);
  gluLookAt(0, 5, 15,
            0, 0, 0,
            0, 1, 0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void CubeSimulationView::paintGL( void )
{
  long int sceneTime = startTime.elapsed();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

    glRotatef(1.0*sceneTime, 0, 1, 0);
    glBegin(GL_TRIANGLES);
      glColor3f(1.0, 0.0, 0.0);
      glVertex3f(0.0, 0.0, 0.0);

      glColor3f(0.0, 0.0, 0.0);
      glVertex3f(5.0, 0.0, 0.0);

      glColor3f(0.0, 0.0, 1.0);
      glVertex3f(5.0, 5.0, 0.0);
    glEnd();

  glPopMatrix();
}
