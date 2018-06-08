#ifndef DEFAULTINFOAREA_H
#define DEFAULTINFOAREA_H

#include <QWidget>

namespace Ui {
class DefaultInfoArea;
}

class DefaultInfoArea : public QWidget
{
    Q_OBJECT
    
public:
    explicit DefaultInfoArea(QWidget *parent = 0);
    ~DefaultInfoArea();
    
private:
    Ui::DefaultInfoArea *ui;
};

#endif // DEFAULTINFOAREA_H
