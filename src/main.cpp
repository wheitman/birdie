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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Load the main QML file
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/src/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    QObject *rootObject = engine.rootObjects().first();

//    QObject *button = rootObject->findChild<QObject *>("helloWorld");
//    if(button){
//        button->setProperty("text","yeet");
//    }
//    else {
//        qDebug("not found");
//    }

    //Load the web configuration file
    QSettings* listenerSettings = new QSettings("../birdie/etc/webapp1.ini",QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");

    //Start the HTTP server
    new HttpListener(listenerSettings, new RequestMapper(&app), &app);

    Canary *myCanary = new Canary();
    myCanary->raiseAlarm(1);
    Canary *newCanary = new Canary();
    if(newCanary->alarmRaised()==1){
        qDebug("GENERAL alarm has been raised.");
    }

    //Enter the main program loop
    return app.exec();
}
