#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "ui_basewindow.h"
LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


LoginMainWindow::LoginMainWindow(QWidget *parent):BaseWindow(parent)
{
    mLoginArea = new LoginWindow(ui->centralWidget);
    ui->verticalLayout->addWidget(mLoginArea);
    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->addStretch();
    this->hideMaxBtn();
    this->setStyleSheet("QMainWindow{color:#E8E8E8;background:#43CD80;}");
    setFixedSize(320,238);
    connect(mLoginArea->ui->btnLogin,SIGNAL(clicked()),this,SIGNAL(loginSuccess()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(onBtnClose()));
}

LoginMainWindow::~LoginMainWindow()
{
    delete mLoginArea;
}

void LoginMainWindow::onBtnClose()
{
    qApp->exit();
}
