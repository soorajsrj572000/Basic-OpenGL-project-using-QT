#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{  
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(ZERO, ZERO, ZERO, ZERO);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(ZERO, ZERO, w, h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3d(ONE, ZERO, ZERO);
    glVertex2f(MINUS_POINT_FIVE, MINUS_POINT_FIVE);
    glColor3d(ZERO, ONE, ZERO);
    glVertex2f(ZERO, POINT_FIVE);
    glColor3d(ZERO, ZERO, ONE);
    glVertex2f(POINT_FIVE, MINUS_POINT_FIVE);
    glEnd();
}
