#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <QObject>
#include <QStringList>
#include <QDir>
#include "birdieqttools.h"

class ContentManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList slideSources READ slideSources NOTIFY slideSourcesChanged)
    Q_PROPERTY(QString slideDir READ getSlideDir NOTIFY slideSourcesChanged)
public:
    ContentManager();
    ContentManager(QObject *parent);
    QStringList slideSources();
    QString getSlideDir();
    QString getPlainSlideDir();
    //QStringList getTickerItems();
private:
    void initSlideDirectory();
signals:
    void slideSourcesChanged();
};

#endif // CONTENTMANAGER_H
