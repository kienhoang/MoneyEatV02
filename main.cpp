#include "mw.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen * splash = new QSplashScreen();
    splash->setPixmap(QPixmap(":/splash/splash/splash.png"));
    splash->show();

    MW w;
    splash->close();
    w.show();
    delete splash;
    return a.exec();
}
