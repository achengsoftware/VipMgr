#include "basewindow.h"
#include "ui_basewindow.h"
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QString>
#include<QGraphicsDropShadowEffect>
BaseWindow::BaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
   // setAttribute(Qt::WA_TranslucentBackground);
    mLocation = this->geometry();
    mIsMax = false;
    mDrag = false;
    setWindowIcon(QIcon(":/win/app"));
    setWindowTitle(QString::fromLocal8Bit("会员管理系统"));
    ui->widgetTitle->installEventFilter(this);
    ui->btnMin->setIcon(QIcon(":/win/min"));
    ui->btnMax->setIcon(QIcon(":/win/max"));
    ui->btnExit->setIcon(QIcon(":/win/exit"));
    connect(ui->btnMin,SIGNAL(clicked()),this,SLOT(onMinClicked()));
    connect(ui->btnMax,SIGNAL(clicked()),this,SLOT(onMaxClicked()));
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(onExitClicked()));
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::hideMaxBtn()
{
    ui->btnMax->hide();
}

bool BaseWindow::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->widgetTitle)
    {
        if(e->type() == QEvent::MouseButtonDblClick)
        {
            onMaxClicked();
            return true;
        }
    }
    return QObject::eventFilter(obj, e);
}

void BaseWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        mDrag = true;
        mDragPos = e->globalPos() - pos();
        e->accept();
    }
}

void BaseWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (mDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - mDragPos);
        e->accept();
    }
}

void BaseWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mDrag = false;
}

void BaseWindow::onMinClicked()
{
    showMinimized();
}

void BaseWindow::onMaxClicked()
{
    if (mIsMax)
    {
        setGeometry(mLocation);
        ui->btnMax->setIcon(QIcon(":/win/max"));
        ui->btnMax->setToolTip(QString::fromLocal8Bit("最大化"));
    }
    else
    {
        mLocation = geometry();
        setGeometry(qApp->desktop()->availableGeometry());
        ui->btnMax->setIcon(QIcon(":/win/max-hover"));
        ui->btnMax->setToolTip(QString::fromLocal8Bit("还原"));
    }
    mIsMax = !mIsMax;
}

void BaseWindow::onExitClicked()
{
    //qApp->exit();
    emit singalClose();
}

void BaseWindow::showWidget()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
    this->repaint();
}

void BaseWindow::onIconIsActived(QSystemTrayIcon::ActivationReason reason)
    {
        switch(reason)
        {
            //点击托盘图标之后松开
        case QSystemTrayIcon::Trigger:
            //双击托盘图标
        case QSystemTrayIcon::DoubleClick:
            {
                showWidget();
                break;
            }
        default:
            break;
        }
    }
