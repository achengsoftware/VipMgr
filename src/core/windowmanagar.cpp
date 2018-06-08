#include "windowmanagar.h"
#include <QApplication>
#include "loginwindow.h"
#include "mainwindow.h"
#include <QTextCodec>
#include <QTranslator>
#include <QProcess>
WindowManagar::WindowManagar(QObject *parent) :
    QObject(parent)
{
    initSystemInfo();
}

void WindowManagar::onLoginSuccess()
{
    MainWindow* mainWin = new MainWindow();
    mWinMap.insert(MAIN_WIN,mainWin);
    ((MainWindow*)mWinMap.value(LOGIN_WIN))->close();

    connect(((SystemTray*)mWinMap.value(TARY_WIN)), SIGNAL(activated(QSystemTrayIcon::ActivationReason)), mainWin, SLOT(onIconIsActived(QSystemTrayIcon::ActivationReason)));
    mainWin->show();
}

void WindowManagar::onExitClient(bool isrestart)
{
    mIsrestart = isrestart;
    qApp->exit(888);//调用exit()，退出应用程序。
}


void WindowManagar::init()
{
    SystemTray* tray = new SystemTray();
    connect(tray, SIGNAL(signalExitClient(bool)),this, SLOT(onExitClient(bool)));
    mWinMap.insert(TARY_WIN,tray);
    tray->show();

    LoginMainWindow* loginWin = new LoginMainWindow();
    connect(loginWin,SIGNAL(loginSuccess()),this,SLOT(onLoginSuccess()));
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), loginWin, SLOT(onIconIsActived(QSystemTrayIcon::ActivationReason)));
    mWinMap.insert(LOGIN_WIN,loginWin);
    loginWin->show();
}

void WindowManagar::restartProcess()
{
    QString appPath("");
    if (!mIsrestart)
    {
        return;
    }
    appPath = QCoreApplication::applicationDirPath();
    appPath.append("/ShopVip.exe");
    bool bret = QProcess::startDetached(appPath, QStringList(appPath));
}

void WindowManagar::initSystemInfo()
{
    //设置编码格式
    QTextCodec *codec = QTextCodec::codecForName("System"); //System
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);

    //加载语言包
    static QTranslator translator;
    bool bret = translator.load(QString(":/qm/qt_zh_CN"));
    qApp->installTranslator(&translator);

    //加载QSS样式表
    QFile qss(":/qss/linkdood");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();


    //设置字体

    QFont font;
    QSysInfo::WinVersion ver = QSysInfo::windowsVersion();
    if(QSysInfo::WV_5_1 < ver){
        font.setPixelSize(96*10/72);
        font.setFamily("Microsoft YaHei");
    }
    else{
        font.setPointSize(10);
        font.setFamily(("simsun"));
    }
    qApp->setFont(font);
}
