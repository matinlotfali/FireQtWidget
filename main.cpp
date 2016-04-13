#include <QApplication>
#include <QSurfaceFormat>
#include "glwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    QSurfaceFormat::setDefaultFormat(fmt);

    GLWidget widget;
    widget.show();
    return a.exec();
}
