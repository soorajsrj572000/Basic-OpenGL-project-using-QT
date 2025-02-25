#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{  
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(ZERO, ZERO, ZERO, ZERO);

    GLfloat vertexPosition[6] =
    {
        MINUS_POINT_FIVE,   MINUS_POINT_FIVE,
        ZERO,               POINT_FIVE,
        POINT_FIVE,         MINUS_POINT_FIVE
    };

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), vertexPosition, GL_STATIC_DRAW);
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(ZERO, ZERO, w, h);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
