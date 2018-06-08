#ifndef MTOOLBTN_H
#define MTOOLBTN_H
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#define TOOLICON_WH 40
#define TOOLWIDGET_W 170
#define TOOLWIDGET_H 30

class MToolBtn: public QPushButton
{
    Q_OBJECT
public:
    MToolBtn(const QString &strImage,const QString &strInfo, int BtnIndex, QWidget *parent=0);
    void SetPress(bool bEnable);
    bool m_bPress;
    int BtnId;
    QString title();
    void mousePressEvent(QMouseEvent *);
signals:
   void ssed();
   void signal_parent(void *);
private slots:
   void slot_ssed();
private:
   bool m_bOver;
  // bool m_bPress;
   QString m_strImage;
   QString m_strInfo;
   void enterEvent(QEvent *);
   void leaveEvent(QEvent *);
  // void mousePressEvent(QMouseEvent *);
   void mouseReleaseEvent(QMouseEvent *);
   void SetOver(bool bEnable);
  // void SetPress(bool bEnable);
   void paintEvent(QPaintEvent *);
   void painterinfo(int,int,QPainter *);
   bool eventFilter(QObject *target, QEvent *event);


};

#endif // MTOOLBTN_H
