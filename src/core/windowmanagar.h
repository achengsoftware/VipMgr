#ifndef WINDOWMANAGAR_H
#define WINDOWMANAGAR_H

#include <QObject>
#include "loginwindow.h"
#include "mainwindow.h"
#include "core/systemtray.h"
class WindowManagar : public QObject
{
    Q_OBJECT
    enum{
        LOGIN_WIN,
        MAIN_WIN,
        TARY_WIN
    };
public:
    explicit WindowManagar(QObject *parent = 0);
    void init();
    void restartProcess();

signals:
    
public slots:
    void onLoginSuccess();
    void onExitClient(bool isrestart);
private:
    void initSystemInfo();
    QMap<int,QObject*>mWinMap;
    bool mIsrestart;
};

#endif // WINDOWMANAGAR_H
