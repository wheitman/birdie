#include "contentmanager.h"

ContentManager::ContentManager(QObject *parent) : QObject(parent)
{
    //empty
}

QQmlListProperty<QString> ContentManager::slideSources(){
    return QQmlListProperty<QString>(this, this,
                                     &ContentManager::appendSource,
                                     &ContentManager::sourceCount,
                                     &ContentManager::source,
                                     &ContentManager::clearSources);
}

void ContentManager::appendSource(QString* source){
    m_slideSources.append(source);
}

int ContentManager::sourceCount() const{
    return m_slideSources.count();
}

QString *ContentManager::source(int index) const{
    return m_slideSources.at(index);
}

void ContentManager::clearSources(){
    m_slideSources.clear();
}

void ContentManager::appendSource(QQmlListProperty<QString>* list, QString* source) {
    reinterpret_cast< ContentManager* >(list->data)->appendSource(source);
}

int ContentManager::sourceCount(QQmlListProperty<QString>* list) {
    return reinterpret_cast< ContentManager* >(list->data)->sourceCount();
}

QString* ContentManager::source(QQmlListProperty<QString>* list, int index) {
    return reinterpret_cast< ContentManager* >(list->data)->source(index);
}

void ContentManager::clearSources(QQmlListProperty<QString>* list) {
    reinterpret_cast< ContentManager* >(list->data)->clearSources();
}
