#include "glwidget.h"
#include "QDebug"
#include "QMouseEvent"
#include "QThread"
#include "QTime"
#include "QGraphicsBlurEffect"

#define _gher 3
#define _wind 0
#define _flame 15
#define _size 400

GLWidget::GLWidget()
{    
    setAutoFillBackground(false);
    setMouseTracking(true);
    resize(_size,_size);

    random = new Random(85533);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(0);
    t.start();
}

void GLWidget::NextColor(unsigned char *r,unsigned char *g, unsigned char *b)
{
    if (*r == 255 && *g > 0 && *b == 0)
    {
        if (*g >= _flame)
            *g = *g - _flame;
        else
            *g = 0;
    }
    else if (*r > 0 && *g == 0 && *b == 0)
    {
        if (*r >= _flame)
            *r = *r - _flame;
        else
            *r = 0;
    }
}

void GLWidget::paintEvent(QPaintEvent *)
{    
    unsigned int i;
    int difference = t.elapsed();
    if(difference == 0)
        difference = 1;
    t.start();
    fpsList.push_back(1000/difference);
    if(fpsList.size() > 500)
        fpsList.erase(fpsList.begin());
    unsigned long sum = 0;
    for (i=0; i<fpsList.size(); i++)
        sum += fpsList.at(i);
    unsigned long fps = sum/fpsList.size();

   unsigned int w = image->width();
   unsigned int h = image->height();

   unsigned char *pixels = image->bits();
   unsigned int j, index, x;
   unsigned char r,g,b;

   for(i=0; i<h-1; i++)
       for(j=0; j<w - _gher + 1; j++)
       {
           index = ((i+1)*w + j)*4;
           r = pixels[index+2];
           g = pixels[index+1];
           b = pixels[index];

           if(random->nextInt(100) < _flame)
               NextColor(&r,&g,&b);
           x = j + random->nextInt(_gher) - _wind;

           index = (i*w+x)*4;
           pixels[index+2] = r;
           pixels[index+1] = g;
           pixels[index] = b;
       }

    QPainter p(this);
    p.setPen(QPen(Qt::white));
    p.drawImage(rect(),*image);
    p.drawText(5,5,width(),height(),00,"FPS: "+ QString::number(fps));
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
    int x,y;
    if(this->width() < _size && this->height() < _size)
    {
        x = event->pos().x();
        y = event->pos().y();
    }
    else if(this->width() > this->height())
    {
        x = event->pos().x() * _size / this->width();
        y = event->pos().y() * _size / this->width();
    }
    else
    {
        x = event->pos().x() * _size / this->height();
        y = event->pos().y() * _size / this->height();
    }
    //qDebug()<< QString("Mouse move (%1,%2)").arg(x).arg(y);

    painter->drawEllipse(x,y,20,20);
    update();
}

