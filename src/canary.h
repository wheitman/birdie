#ifndef CANARY_H
#define CANARY_H

#include <QObject>

class Canary : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentAlarm READ currentAlarm WRITE raiseAlarm NOTIFY currentAlarmChanged)
public:
    int currentAlarm() const {return mCurrentAlarm;}
    void raiseAlarm(int alarm);
    Canary() {}
private:
    static int mCurrentAlarm;
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
