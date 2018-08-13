#ifndef BIRDIEQTTOOLS_H
#define BIRDIEQTTOOLS_H

#include <QObject>
#include "canary.h"
#include <QQmlApplicationEngine>

class BirdieQtTools : public QObject
{
    Q_OBJECT
public:
    BirdieQtTools();
    Canary* getCanary() const{return &mCanary;}
    void setCanary(Canary *newCanary);
    static int engineInit();
    static int setQmlProperty(const QString &objectName, const char *propertyName, const char *propertyValue);
    static QQmlApplicationEngine engine;
    static QQmlApplicationEngine* getEngine() {return &engine;}
private:
    static Canary mCanary;

signals:

public slots:
};

#endif // BIRDIEQTTOOLS_H
