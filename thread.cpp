#include "thread.h"

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

            for(int i=0; i<ui->cursorX.count(); i++)
                ui->painter->drawEllipse(ui->cursorX[i],ui->cursorY[i],20,20);
            for(int i=0; i<ui->cursorX.count()-1; i++)
            {
                ui->cursorX.removeFirst();
                ui->cursorY.removeFirst();
            }
        }

        emit ShowOnUI();
    }
}

inline void MyThread::NextColor(unsigned char *r,unsigned char *g, unsigned char *b)
{
    if(*b == 0)
    {
        if (*r == 255 && *g > 0)
        {
            if(*g > 0)
            {
                if (*g >= _flame)
                    *g = *g - _flame;
                else
                    *g = 0;
            }
        }
        else if (*r > 0 && *g == 0)
        {
            if (*r >= _flame)
                *r = *r - _flame;
            else
                *r = 0;
        }
    }
}
