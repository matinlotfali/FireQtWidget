#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "QWidget"
#include <QPainter>
#include "QTime"
#include "QTimer"
#include "random.h"
#include "stdlib.h"
#include "thread.h"
#include "QList"

#define _gher 3
#define _wind 0
#define _flame 15
#define _size 400

class GLWidget : public QWidget
{
    Q_OBJECT
public:
    GLWidget();    
    QImage *image = NULL;
    QPainter *painter = NULL;
    Random *random;    
    QList<int> cursorX, cursorY;
    int framesShown = 0;

private:            
    void resizeEvent(QResizeEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);    
private slots:
    void Tick();
};

#endif // GLWIDGET_H
