#include "thread.h"
#include "glwidget.h"

MyThread::MyThread(GLWidget *widget,QObject * parent):
    QThread(parent)
{
    ui = widget;
}

void MyThread::run()
{
    for(;;)
    {        
        if(ui->painter)
        {
            ui->painter->drawEllipse(ui->cursorX,ui->cursorY,20,20);

            unsigned int w = ui->image->width();
            unsigned int h = ui->image->height();

            unsigned char *pixels = ui->image->bits();
            unsigned int index;
            unsigned char r,g,b;

            unsigned int last = w * (h - 1) - _gher + 1;
            for (unsigned int i = _wind; i < last; i++)
            {
               index = (i+w)*4;
               r = pixels[index+2];
               g = pixels[index+1];
               b = pixels[index];

               if(ui->random->nextInt(100) < _flame)
                   NextColor(&r,&g,&b);

               index = (i+ui->random->nextInt(_gher) - _wind)*4;
               pixels[index+2] = r;
               pixels[index+1] = g;
               pixels[index] = b;
            }
        }

        emit ShowOnUI();
    }
}

inline void MyThread::NextColor(unsigned char *r,unsigned char *g, unsigned char *b)
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
