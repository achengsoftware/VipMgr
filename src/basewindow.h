#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QSystemTrayIcon>
namespace Ui {
class BaseWindow;
}

class BaseWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();
    void hideMaxBtn();
signals:
    void singalClose();
protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showWidget();
public slots:
    void onMinClicked();
    void onMaxClicked();
    void onExitClicked();
    void onIconIsActived(QSystemTrayIcon::ActivationReason reason);

protected:
    Ui::BaseWindow *ui;
private:
    //标题拖动、双击最大化
    bool mDrag;
    QPoint mDragPos;
    bool mIsMax;
    QRect mLocation;
    QFont mIconFont;
};

#endif // BASEWINDOW_H
