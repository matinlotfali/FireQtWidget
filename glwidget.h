#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QPainter>
#include "QTime"
#include "QTimer"
#include "random.h"
#include "stdlib.h"

using namespace std;

class GLWidget : public QWidget
{
    Q_OBJECT
public:
    GLWidget();

private:    
    QTimer *timer;
    QTime t;
    QImage *image = NULL;
    QPainter *painter = NULL;
    Random *random;
    vector<int> fpsList;
    void resizeEvent(QResizeEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void NextColor(unsigned char *r, unsigned char *g, unsigned char *b);
};

#endif // GLWIDGET_H
