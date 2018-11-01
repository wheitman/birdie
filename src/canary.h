#ifndef CANARY_H
#define CANARY_H

#include <QObject>

class Canary : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentAlarm READ currentAlarm WRITE raiseAlarm NOTIFY currentAlarmChanged)
    Q_PROPERTY(QString title READ getTitle WRITE changeTitle NOTIFY currentAlarmChanged)
    Q_PROPERTY(QString body READ getBody WRITE changeBody NOTIFY currentAlarmChanged)
    Q_PROPERTY(char level READ getLevel WRITE setLevel NOTIFY currentAlarmChanged)
public:
    int currentAlarm() const {return mCurrentAlarm;}
    void raiseAlarm(int alarm);
    QString getTitle() const {return mTitle;}
    void changeTitle(QString title);
    QString getBody() const {return mBody;}
    void changeBody(QString body);
    char getLevel() const {return mLevel;}
    void setLevel(char level);
    Canary() {}
private:
    static int      mCurrentAlarm;
    static QString  mTitle;
    static QString  mBody;
    static char     mLevel;
    /*
     * 0: NO ALARM
     * 1: GENERAL ALARM
     * 2: WEATHER ALARM
     * 3: FIRE ALARM
     * 4: CHEMICAL ALARM
     * 5: VIOLENCE ALARM
     */
signals:
    void currentAlarmChanged();
};

#endif // CANARY_H
