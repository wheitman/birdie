#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include <QObject>
#include <QQmlListProperty>

class ContentManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<QString> slideSources READ slideSources NOTIFY slideSourcesChanged)
public:
    explicit ContentManager(QObject *parent = nullptr);

    QQmlListProperty<QString> slideSources();
    void appendSource(QString*);
    int sourceCount() const;
    QString *source(int) const;
    void clearSources();
private:
    static void appendSource(QQmlListProperty<QString>*, QString*);
    static int sourceCount(QQmlListProperty<QString>*);
    static QString* source(QQmlListProperty<QString>*,int);
    static void clearSources(QQmlListProperty<QString>*);
    QList<QString *> m_slideSources;
signals:
    void slideSourcesChanged();
public slots:
};

#endif // CONTENTMANAGER_H
