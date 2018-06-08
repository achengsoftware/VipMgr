#include "systemtray.h"
#include <QWidgetAction>

SystemTray::SystemTray(QWidget *parent):QSystemTrayIcon(parent)
{
    tray_menu = new QMenu();
    action_logout = new QAction(this);
    action_loginoff = new QAction(this);
    tray_menu->addAction(action_loginoff);
    tray_menu->addAction(action_logout);

    tray_menu->setFixedWidth(80);
    this->setToolTip(tr("会员管理系统"));
    action_loginoff->setText(tr("注销"));
    action_logout->setText(tr("退出"));
    this->setIcon(QIcon(":/win/app"));

    QObject::connect(this, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
                     SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
    QObject::connect(action_logout, SIGNAL(triggered()), this, SLOT(onLoginOut()));
    QObject::connect(action_loginoff, SIGNAL(triggered()), this, SLOT(onLoginOff()));
    this->setContextMenu(tray_menu);
}

void SystemTray::onLoginOff(){
    emit signalExitClient(true);
}

void SystemTray::onLoginOut(){
    emit signalExitClient(false);
}

void SystemTray::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    //点击托盘图标之后松开
    case QSystemTrayIcon::Trigger:
    {
        break;
    }
        //双击托盘图标
    case QSystemTrayIcon::DoubleClick:
    {
        break;
    }
    default:
        break;
    }
}
