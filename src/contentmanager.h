#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <QObject>
#include <QStringList>

class ContentManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList slideSources READ slideSources NOTIFY slideSourcesChanged)
public:
    ContentManager();
    ContentManager(QObject *parent);
    QStringList slideSources();
signals:
    void slideSourcesChanged();
};

#endif // CONTENTMANAGER_H
