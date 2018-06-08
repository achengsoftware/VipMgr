#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QToolBox>
#include <QStackedLayout>
#include <QStackedWidget>
#include "controls/mtoolbtn.h"
#include "basewindow.h"
#include "data/taskData.h"
#include<QMap>
#include<QList>

class MainWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    
signals:
    
public slots:
    void onSetBoxItem(void *object);
    void onBtnClose();
private:
    void initMenu();//��ʼ������˵�
    void getTabInfo(MGRTYPE type, QString& icon,QString& text);
    void initContextAreaWidgets();
private:
    QList<MToolBtn*> mLeftMenuBtns; // �Զ��尴ť
    QToolBox *mToolbox;
    QStackedWidget *mStackedWidget;
    QMap<MGRTYPE,QList<taskInfo> >mMapMgrsBtns;
    QMap<int,QWidget*>mMapContextAreas;//��������ҳ��
};

#endif // MAINWINDOW_H
