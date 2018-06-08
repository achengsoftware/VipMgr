#include "qpopbutton.h"
#include <QMenu>
QPopButton::QPopButton(QWidget *parent)
    :QPushButton(parent)
{
    menu = new QMenu(this);
    connect(this,SIGNAL(clicked()),this,SLOT(popmenu()));
    this->setFocusPolicy(Qt::NoFocus);
}
QMenu *QPopButton::getmenu()
{
    return menu;

}
void QPopButton::popmenu()
{
    QPoint pos;
    int x = pos.x();
    int y = pos.y();
    pos.setX(x+this->geometry().width()/2);
    pos.setY(y+this->geometry().height());
    menu->exec(this->mapToGlobal(pos));
}
