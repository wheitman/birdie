#include "birdieqttools.h"
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QTextStream>

Q_GLOBAL_STATIC(QQmlApplicationEngine, appEngine)

QDir BirdieQtTools::mRoot("/");

QFile BirdieQtTools::mManifestFile(QSettings("Heitman", "Birdie").value("root").toString()+"/files/manifest.json");

BirdieQtTools::BirdieQtTools(){
    initSettings();
}

void BirdieQtTools::initSettings(){
    QSettings *settings = new QSettings("Heitman", "Birdie");
    mRoot = QDir(settings->value("root").toString());
    if(settings->value("root").toString().toLatin1()==""){
        qWarning("BirdieQtTools: could not read root config. Setting root to default.");
        settings->setValue("root",QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first()+"/");
    }
    else{
        //qInfo("Root is: "+mRoot.absolutePath().toLatin1());
    }
}

QString BirdieQtTools::getManifestString(){
    QFile manifest(QSettings("Heitman", "Birdie").value("root").toString()+"/files/manifest.json");
    manifest.open(QFile::ReadOnly);
    QTextStream in(&manifest);
    QString manifestString = in.readAll();
    manifest.close();
    return manifestString;
}

int BirdieQtTools::engineInit(){
    appEngine->load(QUrl(QStringLiteral("qrc:/src/main.qml")));
    if (appEngine->rootObjects().isEmpty())
        return -1;
    return 0;
}

int BirdieQtTools::setQmlProperty(const QString &objectName, const char * propertyName, const char * propertyValue){
    QObject *rootObject = appEngine->rootObjects().first();
    if(!rootObject)
        return -1; //check for empty object
    QObject *targetObject = rootObject->findChild<QObject *>(objectName);
    if(targetObject){
        targetObject->setProperty(propertyName,propertyValue);
        return 0;
    }
    return -1;
}
