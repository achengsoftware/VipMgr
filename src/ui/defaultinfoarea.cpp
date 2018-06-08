#include "defaultinfoarea.h"
#include "ui_defaultinfoarea.h"

DefaultInfoArea::DefaultInfoArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefaultInfoArea)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
}

DefaultInfoArea::~DefaultInfoArea()
{
    delete ui;
}
