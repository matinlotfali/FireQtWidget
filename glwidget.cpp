#include "glwidget.h"
#include "QDebug"
#include "QMouseEvent"
#include "thread"
#include "QTime"
#include "QGraphicsBlurEffect"

GLWidget::GLWidget()
{    
    setAutoFillBackground(false);
    setMouseTracking(true);    
    setCursor(Qt::BlankCursor);
    resize(_size,_size);

    random = new Random(85533);    

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Tick()));
    timer->start(1000);

    MyThread *thread = new MyThread(this,this);
    connect(thread, SIGNAL(ShowOnUI()),this,SLOT(update()));
    thread->start();    
}

void GLWidget::Tick()
{
    setWindowTitle("Fire - FPS: "+ QString::number(framesShown));
    framesShown = 0;
}

void GLWidget::paintEvent(QPaintEvent *)
{
    framesShown++;

    QPainter p(this);
    p.setPen(QPen(Qt::white));
    p.drawImage(rect(),*image);        
}

void GLWidget::mousePressEvent(QMouseEvent *)
{
    //qDebug()<< "Mouse press";
}

void GLWidget::mouseReleaseEvent(QMouseEvent *)
{
    //qDebug()<< "Mouse release";
}

void GLWidget::resizeEvent(QResizeEvent *)
{
    delete painter;
    delete image;

    int w, h;
    if(width() <= _size && height() <= _size)
    {
        w = width();
        h = height();
    }
    else if(width() > height())
    {
        w = _size;
        h = _size * height() / width();
    }
    else
    {
        h = _size;
        w = _size * width() / height();
    }

    qDebug()<< "Resize: "<<width()<<"x"<<height()<<"->"<<w<<"x"<<h;

    image = new QImage(w,h,QImage::Format_ARGB32_Premultiplied);
    painter = new QPainter(image);
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::yellow);
    painter->fillRect(image->rect(),Qt::black);
    painter->drawLine(0,h-1,w-1,h-1);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{    
    if(this->width() < _size && this->height() < _size)
    {
        cursorX.append(event->pos().x());
        cursorY.append(event->pos().y());
    }
    else if(this->width() > this->height())
    {
        cursorX.append(event->pos().x() * _size / this->width());
        cursorY.append(event->pos().y() * _size / this->width());
    }
    else
    {
        cursorX.append(event->pos().x() * _size / this->height());
        cursorY.append(event->pos().y() * _size / this->height());
    }
    //qDebug()<< QString("Mouse move (%1,%2)").arg(x).arg(y);        
}

