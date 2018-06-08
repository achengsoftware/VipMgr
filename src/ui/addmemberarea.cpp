#include "addmemberarea.h"
#include "ui_addmemberarea.h"

AddMemberArea::AddMemberArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMemberArea)
{
    ui->setupUi(this);
}

AddMemberArea::~AddMemberArea()
{
    delete ui;
}
