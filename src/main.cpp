#include <QApplication>
#include "core/windowmanagar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    WindowManagar manager;
    manager.init();
    int ret = a.exec();
    if ( 888 == ret)
    {
        manager.restartProcess();
        return 0;
    }
    return ret;
}
