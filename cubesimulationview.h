#ifndef CUBESIMULATIONVIEW_H
#define CUBESIMULATIONVIEW_H

#include <QtOpenGL>

class CubeSimulationView : public QGLWidget
{
  Q_OBJECT
private:
  QTime startTime;
  QTimer timer;

public:
  explicit CubeSimulationView(QWidget *parent = 0);

signals:

public slots:


protected:
  void initializeGL( void );
  void resizeGL( int, int );
  void paintGL( void );
};

#endif // CUBESIMULATIONVIEW_H
