#include "mtoolbtn.h"
#include  <QDebug>
#include "mainwindow.h"
MToolBtn::MToolBtn(const QString &strImage,const QString &strInfo,int btnindex, QWidget *parent)
    :QPushButton(parent),m_bOver(false),m_bPress(false),m_strImage(strImage),m_strInfo(strInfo)//ע�⣺�˴��ĸ�����дʱ�治�����߰�ť
{
    // �ı���ɫ
   // ToolParent = parent;
    BtnId = btnindex;
    QPalette objPalette = palette();
    objPalette.setColor(QPalette::ButtonText, QColor( 0, 0, 0));
    setPalette(objPalette);
    // �ı�����
    //QFont &objFont = const_cast<QFont &>(font());
    //objFont.setWeight(QFont::Bold);
    // ��ʽ
    //setStyleSheet( "QToolButton{border:0px;color:white;}");
    // ��С
    setIconSize(QSize(90,30));//Ϊʲôʵ��������仰������button�Ĵ�С��icon�ĳ���С��button�ĳ��ȾͲ��������ı������������̫��
    resize(TOOLWIDGET_W,TOOLWIDGET_H);

    // ����ͼ���ı�
    setIcon(QIcon(strImage));
    setText(strInfo);

    // ����ss�źŲۣ���ʾ��ť����ʱ
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
    ev->ignore();//�����ϴ����丸����ɶ����,��QPushButton������ʲô���ã�
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
    // ����m_bOver��־λ
      m_bPress = bEnable;

    // ����
      update();
    }
}

QString MToolBtn::title()
{
    return m_strInfo;
}

//���Ƶ�ȻҪ�ڰ�ť��paintEvent�¼���������ʵ���ˣ�����������ʾ������ע�͵ĺ���ϸ���ҾͲ���˵�ˣ�
// �ػ��¼�
void MToolBtn::paintEvent(QPaintEvent * event)
{
   QPainter painter(this);
  // �����ť������
  if(m_bPress)
  {
  // ���Ʊ�����ʱ��Ч��
   //painterinfo( 200, 200,&painter);
    this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/clicksmall)");

  }
  else if(m_bOver == true) // �����ťû�б����²�������Ƶ���ť��
  {
   // ��������Ƶ���ť�ϵİ�ťЧ��
    this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small-enter)");

  }
  else if(m_bOver == false)
  {
      this->setStyleSheet("border:1px solid blue;border-image:url(:/ctrl/small)");

  }
// ���û�����ػ��¼�����ʾͼ���ı���
  QPushButton::paintEvent( event);

}
// ���Ʊ�������
void MToolBtn::painterinfo( int nTopPartOpacity, int nBottomPartOpacity,QPainter *pPainter)
{
  // ���û���
  QPen objPen(Qt::NoBrush, 1);
  pPainter->setPen(objPen);
  // ���ý��仭ˢ
  QLinearGradient objLinear(rect().topLeft(),rect().bottomLeft());
  // ������ɫ��͸����
  objLinear.setColorAt( 0,QColor( 3, 91, 251,nTopPartOpacity));
  // �м���ɫ��͸����
  objLinear.setColorAt( 0.5,QColor( 80, 80, 80, 200));
  // �ײ���ɫ��͸����
  objLinear.setColorAt( 1,QColor( 3, 91, 251,nBottomPartOpacity));
  QBrush objBrush(objLinear);
  pPainter->setBrush(objBrush);
  // ��Բ�Ǿ���
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

