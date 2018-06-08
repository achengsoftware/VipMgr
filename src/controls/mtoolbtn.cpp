#include "mtoolbtn.h"
#include  <QDebug>
#include "mainwindow.h"
MToolBtn::MToolBtn(const QString &strImage,const QString &strInfo,int btnindex, QWidget *parent)
    :QPushButton(parent),m_bOver(false),m_bPress(false),m_strImage(strImage),m_strInfo(strInfo)//注意：此处的父对象不写时绘不出工具按钮
{
    // 文本颜色
   // ToolParent = parent;
    BtnId = btnindex;
    QPalette objPalette = palette();
    objPalette.setColor(QPalette::ButtonText, QColor( 0, 0, 0));
    setPalette(objPalette);
    // 文本粗体
    //QFont &objFont = const_cast<QFont &>(font());
    //objFont.setWeight(QFont::Bold);
    // 样式
    //setStyleSheet( "QToolButton{border:0px;color:white;}");
    // 大小
    setIconSize(QSize(90,30));//为什么实际上是这句话控制着button的大小？icon的长度小点button的长度就不会随这文本的增大而增大太多
    resize(TOOLWIDGET_W,TOOLWIDGET_H);

    // 设置图像文本
    setIcon(QIcon(strImage));
    setText(strInfo);

    // 连接ss信号槽，表示按钮按下时
    connect(this,SIGNAL(ssed()),this,SLOT(slot_ssed()));
    setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small)");
}
void MToolBtn::enterEvent(QEvent *)
{
    SetOver(true);

}
void MToolBtn::leaveEvent(QEvent *)
{
    SetOver(false);

}
void MToolBtn::SetOver(bool bEnable)
{
    if(bEnable!=m_bOver)
    {
        m_bOver = bEnable;
        update();
    }
}
void MToolBtn::mousePressEvent(QMouseEvent *ev)
{   
    emit ssed();
    ev->ignore();//继续上传给其父类有啥作用,向QPushButton传递有什么作用？
}
void MToolBtn::mouseReleaseEvent(QMouseEvent *ev)
{
    //SetPress(false);
    ev->ignore();

}
void MToolBtn::slot_ssed()
{
    SetPress(true);
    emit signal_parent(this);

}
void MToolBtn::SetPress( bool bEnable)
{
    if(bEnable == true)
    {
        this->setDown(true);
    }
    else
    {
        this->setDown(false);
    }
    if(bEnable!=m_bPress)
    {
    // 设置m_bOver标志位
      m_bPress = bEnable;

    // 更新
      update();
    }
}

QString MToolBtn::title()
{
    return m_strInfo;
}

//绘制当然要在按钮的paintEvent事件处理函数中实现了，代码如下所示，代码注释的很详细，我就不多说了：
// 重绘事件
void MToolBtn::paintEvent(QPaintEvent * event)
{
   QPainter painter(this);
  // 如果按钮被按下
  if(m_bPress)
  {
  // 绘制被按下时的效果
   //painterinfo( 200, 200,&painter);
    this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/clicksmall)");

  }
  else if(m_bOver == true) // 如果按钮没有被按下并且鼠标移到按钮上
  {
   // 绘制鼠标移到按钮上的按钮效果
    this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small-enter)");

  }
  else if(m_bOver == false)
  {
      this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small)");

  }
// 调用基类的重绘事件以显示图像文本等
  QPushButton::paintEvent( event);

}
// 绘制背景渐变
void MToolBtn::painterinfo( int nTopPartOpacity, int nBottomPartOpacity,QPainter *pPainter)
{
  // 设置画笔
  QPen objPen(Qt::NoBrush, 1);
  pPainter->setPen(objPen);
  // 设置渐变画刷
  QLinearGradient objLinear(rect().topLeft(),rect().bottomLeft());
  // 顶部颜色和透明度
  objLinear.setColorAt( 0,QColor( 3, 91, 251,nTopPartOpacity));
  // 中间颜色和透明度
  objLinear.setColorAt( 0.5,QColor( 80, 80, 80, 200));
  // 底部颜色和透明度
  objLinear.setColorAt( 1,QColor( 3, 91, 251,nBottomPartOpacity));
  QBrush objBrush(objLinear);
  pPainter->setBrush(objBrush);
  // 画圆角矩形
  pPainter->drawRoundedRect(rect(), 5, 5);

    //pPainter->setBrush(QBrush(QColor(10,10,10),Qt::SolidPattern));
    //pPainter->drawRect(rect());
}
bool MToolBtn::eventFilter(QObject *target, QEvent *event)
{
    if(event->type() == QEvent::Enter)
    {
        this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small-enter)");
    }
    else if(event->type() == QEvent::Leave )
    {
        this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small)");

    }
    else if(((QMouseEvent*)event)->button() == Qt::LeftButton)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/clicksmall)");

        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/clicksmall)");

            emit signal_parent(this);
        }
    }
    return QWidget::eventFilter(target,event);
}

