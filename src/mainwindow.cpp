#include "mainwindow.h"
#include "ui_basewindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    BaseWindow(parent)
{
    this->resize(920,600);
    mToolbox = new QToolBox(ui->centralWidget);
    mToolbox->setObjectName("leftToolBox");
    mToolbox->setFixedWidth(200);
    mToolbox->layout()->setSpacing(0);
    mToolbox->layout()->setContentsMargins(1,0,0,0);
    mStackedWidget = new QStackedWidget(ui->centralWidget);

    QHBoxLayout* contentLayout = new QHBoxLayout(ui->centralWidget);
    contentLayout->addWidget(mToolbox);
    contentLayout->addWidget(mStackedWidget);
    contentLayout->setSpacing(0);
    contentLayout->setContentsMargins(0,0,0,0);
    QWidget* widget = new QWidget(ui->centralWidget);
    widget->setLayout(contentLayout);
    ui->verticalLayout->addWidget(widget);
    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->setContentsMargins(1,1,1,1);
    connect(ui->btnExit,SIGNAL(clicked()),this,SLOT(onBtnClose()));
    initMenu();

}


void MainWindow::onSetBoxItem(void *object)
{
    for( int nIndex = 0;nIndex<mLeftMenuBtns.size();++nIndex)
    {
        if(mLeftMenuBtns.at(nIndex)!=object)
        {
            mLeftMenuBtns.at(nIndex)->SetPress( false);
        }
    }
    MToolBtn* btn = (MToolBtn*)object;
    qDebug()<<Q_FUNC_INFO<<btn->title()<<","<<btn->BtnId;
}

void MainWindow::onBtnClose()
{
    hide();
}

void MainWindow::initMenu()
{
    QList<taskInfo> list;
    QStringList text;

    text<<tr("添加会员")<<tr("查询会员")<<tr("编辑会员")<<tr("删除会员");
    for(int i=0;i<text.size();++i){
        taskInfo info;
        info.id = TASKTYPE(TASK_TYPE_ADD_MEMBER+i);
        info.name = text.at(i).toStdString();
        list.push_back(info);
    }
    mMapMgrsBtns.insert(MGR_NUMBER,list);
    list.clear();
    text.clear();

    text<<tr("添加员工")<<tr("查询员工")<<tr("编辑员工")<<tr("删除员工")
       <<tr("添加工种")<<tr("查询工种")<<tr("编辑工种")<<tr("删除工种");
    for(int i=0;i<text.size();++i){
        taskInfo info;
        info.id = TASKTYPE(TASK_TYPE_ADD_STAFF+i);
        info.name = text.at(i).toStdString();
        list.push_back(info);
    }
    mMapMgrsBtns.insert(MGR_STDFF,list);
    list.clear();
    text.clear();

    text<<tr("添加商品")<<tr("查询商品")<<tr("编辑商品")<<tr("删除商品");
    for(int i=0;i<text.size();++i){
        taskInfo info;
        info.id = TASKTYPE(TASK_TYPE_ADD_GOODS+i);
        info.name = text.at(i).toStdString();
        list.push_back(info);
    }
    mMapMgrsBtns.insert(MGR_GOOGS,list);
    list.clear();
    text.clear();

    text<<tr("会员结账")<<tr("非会员结账");
    for(int i=0;i<text.size();++i){
        taskInfo info;
        info.id = TASKTYPE(TASK_TYPE_VIP_CHECK+i);
        info.name = text.at(i).toStdString();
        list.push_back(info);
    }
    mMapMgrsBtns.insert(MSG_CHECK,list);
    list.clear();
    text.clear();

    text<<tr("会员消费查询")<<tr("所有消费查询");
    for(int i=0;i<text.size();++i){
        taskInfo info;
        info.id = TASKTYPE(TASK_TYPE_VIP_CONSUMPTION+i);
        info.name = text.at(i).toStdString();
        list.push_back(info);
    }
    mMapMgrsBtns.insert(MGR_CONSUMPTION,list);

    QList<MGRTYPE> keys = mMapMgrsBtns.keys();
    for(int i=0;i<keys.size();++i){
        QList<taskInfo> infos = mMapMgrsBtns.value(keys.at(i));
        QWidget *widget = new QWidget(mToolbox);
        QGridLayout *gridLayout = new QGridLayout(widget);
        gridLayout->setContentsMargins(0, 0, 0, 0);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->setMargin(0);
        layout->setSpacing(0);//button之间没有空隙
        for(int j=0;j<infos.size();j++){
            // 图像资源路径
            QString strImage = QString(":images/%1.png").arg(i*j+ 1);
            MToolBtn* btn = new MToolBtn(strImage,infos.at(j).name.c_str(),infos.at(j).id);
            layout->addWidget(btn);
            mLeftMenuBtns.push_back(btn);
            connect(btn,SIGNAL(signal_parent(void *)),this,SLOT(onSetBoxItem( void*)));
        }
        layout->addStretch(0);
        gridLayout->addLayout(layout, 0, 0, 0, 0);
        QString icon,title;
        getTabInfo(keys.at(i),icon,title);
        mToolbox->addItem(widget,QIcon(icon),title);
    }
}

void MainWindow::getTabInfo(MGRTYPE type, QString &icon, QString &text)
{
    switch(type){
    case MGR_NUMBER:
    {
        icon =":ctrl/info";
        text = tr("会员管理");
        break;
    }
    case MGR_STDFF:
    {
        icon =":ctrl/record";
        text = tr("员工管理");
        break;
    }
    case MGR_GOOGS:
    {
        icon =":ctrl/sys-set";
        text = tr("商品管理");
        break;
    }
    case MSG_CHECK:
    {
        icon =":ctrl/set";
        text = tr("结账管理");
        break;
    }
    case MGR_CONSUMPTION:
    {
        icon =":ctrl/main";
        text = tr("消费管理");
        break;
    }
    }
}
