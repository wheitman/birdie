#ifndef BIRDIEQTTOOLS_H
#define BIRDIEQTTOOLS_H

#include <QObject>
#include "canary.h"
#include <QQmlApplicationEngine>
#include <QDir>
#include <QSettings>
#include <QCoreApplication>

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
    QDir getRootDir() const {return mRoot;}
private:
    static Canary mCanary;
    static QDir mRoot;
    void initSettings();
signals:

public slots:
};

#endif // BIRDIEQTTOOLS_H
