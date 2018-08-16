#include "contentmanager.h"
#include <QDir>

ContentManager::ContentManager(QObject *parent) : QObject(parent)
{
    //empty
}

ContentManager::ContentManager(){
    //empty
}

QStringList ContentManager::slideSources(){
    QStringList sourceList;
    QDir directory("C:/slides");
    sourceList << directory.entryList(QStringList() << "*.jpg" << "*JPG",QDir::Files);
    return sourceList;
}
