#ifndef CANARY_H
#define CANARY_H

#include <QObject>

class Canary : QObject
{
    Q_OBJECT
public:
    int raiseAlarm(int alarmType);
    int alarmRaised();
    int raiseAllClear();
    Canary() {}
private:
    static bool generalAlarmRaised;
    static bool weatherAlarmRaised;
    static bool fireAlarmRaised;
    static bool chemicalAlarmRaised;
    static bool violenceAlarmRaised;
};

#endif // CANARY_H
