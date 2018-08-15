#include "contentmanager.h"
#include <QDirIterator>

ContentManager::ContentManager(QObject *parent) : QObject(parent)
{
    //empty
}

ContentManager::ContentManager(){
    //empty
}

QStringList ContentManager::slideSources(){
    QDirIterator slideDirIterator("C:/slides",QDirIterator::Subdirectories);
    QStringList sourceList;
    while(slideDirIterator.hasNext()){
        sourceList << "slideDirIterator";
    }
    sourceList << "Done";
    return sourceList;
}
