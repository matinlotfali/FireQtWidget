#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class GLWidget;

class MyThread: public QThread
{
    Q_OBJECT

    GLWidget *ui;
    void run();
    inline void NextColor(unsigned char *r,unsigned char *g, unsigned char *b);

public:
    MyThread(GLWidget *widget,QObject * parent = 0);

signals:
    void ShowOnUI();
};

#endif // THREAD_H
