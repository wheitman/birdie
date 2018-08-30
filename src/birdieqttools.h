#ifndef BIRDIEQTTOOLS_H
#define BIRDIEQTTOOLS_H

#include <QObject>
#include "canary.h"
#include <QQmlApplicationEngine>
#include <QDir>
#include <QSettings>
#include <QFileInfo>
#include <QCoreApplication>

class BirdieQtTools : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QDir rootDir READ getRootDir NOTIFY rootDirChanged)
    Q_PROPERTY(QString manifestPath READ getManifestPath NOTIFY manifestPathChanged)
    Q_PROPERTY(QString manifestString READ getManifestString NOTIFY manifestStringChanged)
public:
    BirdieQtTools();
    Canary* getCanary() const{return &mCanary;}
    void setCanary(Canary *newCanary);
    static int engineInit();
    static int setQmlProperty(const QString &objectName, const char *propertyName, const char *propertyValue);
    static QQmlApplicationEngine engine;
    static QQmlApplicationEngine* getEngine() {return &engine;}
    QDir getRootDir() const {return mRoot;}
    QString getManifestPath() const {return QFileInfo(mManifestFile).absoluteFilePath();}
    QString getManifestString();
private:
    static Canary mCanary;
    static QDir mRoot;
    static QFile mManifestFile;
    void initSettings();
signals:
    void rootDirChanged();
    void manifestPathChanged();
    void manifestStringChanged();
public slots:
};

#endif // BIRDIEQTTOOLS_H
