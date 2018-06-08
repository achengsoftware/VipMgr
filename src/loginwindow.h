#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include"basewindow.h"
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    
public:
    Ui::LoginWindow *ui;
};

class LoginMainWindow:public BaseWindow{
    Q_OBJECT
signals:
    void loginSuccess();
public:
    explicit LoginMainWindow(QWidget *parent = 0);
    ~LoginMainWindow();
protected slots:
    void onBtnClose();
private:
    LoginWindow*mLoginArea;
};

#endif // LOGINWINDOW_H
