#include "contentmanager.h"
#include <QSettings>
#include <QCoreApplication>

ContentManager::ContentManager(QObject *parent) : QObject(parent)
{
    initSlideDirectory();
}

ContentManager::ContentManager(){
    initSlideDirectory();
}

void ContentManager::initSlideDirectory(){
    BirdieQtTools tools;
    if(!QDir(tools.getRootDir().absolutePath().toLatin1().append("/slides")).exists()){
        qInfo("Making slide directory");
        QDir().mkdir(tools.getRootDir().absolutePath().toLatin1());
        QDir().mkdir(tools.getRootDir().absolutePath().toLatin1().append("/slides"));
    }
}

QStringList ContentManager::slideSources(){
    BirdieQtTools tools;
    QStringList sourceList;
    QDir directory(tools.getRootDir().absolutePath().toLatin1().append("/slides"));
    directory.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    sourceList << directory.entryList(QStringList() << "*.jpg" << "*JPG",QDir::Files);
    return sourceList;
}

QString ContentManager::getSlideDir(){
    BirdieQtTools tools;
    return "file:///"+tools.getRootDir().absolutePath().toLatin1().append("/slides");
}
