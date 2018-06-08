#ifndef QPOPBUTTON_H
#define QPOPBUTTON_H
#include <QPushButton>
class QMenu;

class QPopButton:public QPushButton
{
    Q_OBJECT
public:
   explicit QPopButton(QWidget *parent = 0);
    QMenu *getmenu();
private slots:
    void popmenu();

private:
    QMenu *menu;

};

#endif // QPOPBUTTON_H
