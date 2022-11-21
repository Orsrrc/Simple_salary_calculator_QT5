#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    /* 设置白色背景 */
    w.setStyleSheet("background-color: white;");
    return a.exec();
}
