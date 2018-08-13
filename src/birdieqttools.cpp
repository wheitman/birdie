#include "birdieqttools.h"
#include "canary.h"
#include <QQmlApplicationEngine>

Q_GLOBAL_STATIC(QQmlApplicationEngine, appEngine)

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
