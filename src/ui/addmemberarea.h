#ifndef ADDMEMBERAREA_H
#define ADDMEMBERAREA_H

#include <QWidget>

namespace Ui {
class AddMemberArea;
}

class AddMemberArea : public QWidget
{
    Q_OBJECT
    
public:
    explicit AddMemberArea(QWidget *parent = 0);
    ~AddMemberArea();
    
private:
    Ui::AddMemberArea *ui;
};

#endif // ADDMEMBERAREA_H
