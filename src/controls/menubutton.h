#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include <QToolButton>
class MenuButton:public QToolButton
{
public:
    MenuButton(QWidget *parent = 0);
    ~MenuButton(){}
protected:
    bool eventFilter(QObject *target, QEvent *event);
};

#endif // MENUBUTTON_H
