#include "menubutton.h"
#include <QMouseEvent>
MenuButton::MenuButton(QWidget *parent):QToolButton(parent)
{
    installEventFilter(this);
}
bool MenuButton::eventFilter(QObject *target, QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        this->setStyleSheet("border-image: url(:/ctrl/mn-enter.png)");
    }
    else if(event->type() == QEvent::Leave )
    {
        this->setStyleSheet("border-image: url(:/ctrl/mn-leave.png)");
    }
    else if(((QMouseEvent*)event)->button() == Qt::LeftButton)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            this->setStyleSheet("border-image: url(:/ctrl/mn-down.png)");
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            this->setStyleSheet("border-image: url(:/ctrl/mn-leave.png)");

        }
    }
    return QWidget::eventFilter(target,event);
}
