#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QWidget>
class SystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTray(QWidget *parent = 0);

signals:
    void signalExitClient(bool isrestart);
public slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);
    void onLoginOff();
    void onLoginOut();

protected:
    QMenu *tray_menu; //ÍÐÅÌ²Ëµ¥
    QAction *action_loginoff; //×¢Ïú
    QAction *action_logout; //ÍË³ö
};

#endif // SYSTEMTRAY_H
