#include "contentmanager.h"

ContentManager::ContentManager(QObject *parent) : QObject(parent)
{
    //empty
}

ContentManager::ContentManager(){
    //empty
}

QStringList ContentManager::slideSources(){
    QStringList sourceList;
    sourceList << "My ass";
    return sourceList;
}
