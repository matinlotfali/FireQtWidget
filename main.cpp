#include <QApplication>
#include "glwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GLWidget widget;
    widget.show();
    return a.exec();
}
