#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QFile>
#include <QDir>
#include <QString>
#include "httplistener.h"
#include "httprequesthandler.h"
#include "requestmapper.h"
#include "canary.h"
#include <QtGlobal>
#include "birdieqttools.h"
#include "contentmanager.h"

using namespace stefanfrings;

QString searchConfigFile() {
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QFile file;
    file.setFileName(binDir+"/webapp1.ini");
    if (!file.exists()) {
        file.setFileName(binDir+"/etc/webapp1.ini");
        if (!file.exists()) {
            file.setFileName(binDir+"/../etc/webapp1.ini");
            if (!file.exists()) {
                file.setFileName(binDir+"/../"+appName+"/etc/webapp1.ini");
                if (!file.exists()) {
                    file.setFileName(binDir+"/../../"+appName+"/etc/webapp1.ini");
                    if (!file.exists()) {
                        file.setFileName(binDir+"/../../../../../"+appName+"/etc/webapp1.ini");
                        if (!file.exists()) {
                            file.setFileName(QDir::rootPath()+"etc/webapp1.ini");
                        }
                    }
                }
            }
        }
    }
    if (file.exists()) {
        QString configFileName=QDir(file.fileName()).canonicalPath();
        qDebug("using config file %s", qPrintable(configFileName));
        return configFileName;
    }
    else {
        qFatal("config file not found");
    }
}

Q_GLOBAL_STATIC(Canary, myCanary)

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Canary>("com.birdie.canary",1,0,"Canary");
    qmlRegisterType<ContentManager>("com.birdie.content",1,0,"ContentManager");
    qmlRegisterType<BirdieQtTools>("com.birdie.qttools",1,0,"BirdieQtTools");

    //Load the main QML file
    //QQmlApplicationEngine engine;
    //QQmlApplicationEngine *engine = &BirdieQtTools::engine;
    //engine.load(QUrl(QStringLiteral("qrc:/src/main.qml")));
    //if (engine.rootObjects().isEmpty())
    //    return -1;

//    QObject *rootObject = engine.rootObjects().first();

//    QObject *button = rootObject->findChild<QObject *>("helloWorld");
//    Canary *mainCanary = rootObject->findChild<Canary *>();
//    if(mainCanary)
//        mainCanary->setProperty("currentAlarm",2);
//    if(button){
//        button->setProperty("text","yeet");
//    }
//    else {
//        qDebug("not found");
//    }

    BirdieQtTools::engineInit();
    BirdieQtTools::setQmlProperty("helloWorld","text","yeet");

    //Load the web configuration file
    QSettings* listenerSettings = new QSettings("../birdie/etc/webapp1.ini",QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");

    //Start the HTTP server
    new HttpListener(listenerSettings, new RequestMapper(&app), &app);

    myCanary->raiseAlarm(2);
    Canary *newCanary = new Canary();
    if(newCanary->currentAlarm()==1){
        qDebug("GENERAL alarm has been raised.");
    }
    else{
        std::string alarm = "Current code is: "+std::to_string(newCanary->currentAlarm());
        qDebug(alarm.c_str());
    }

    //Enter the main program loop
    return app.exec();
}
