#ifndef CANARY_H
#define CANARY_H

#include <QObject>

class Canary : QObject
{
    Q_OBJECT
public:
    static int raiseAlarm(int alarmType);
    static int alarmRaised();
    static int raiseAllClear();
private:
    Canary() {}
    static bool generalAlarmRaised;
    static bool weatherAlarmRaised;
    static bool fireAlarmRaised;
    static bool chemicalAlarmRaised;
    static bool violenceAlarmRaised;
};

#endif // CANARY_H
