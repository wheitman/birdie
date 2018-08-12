#include "canary.h"

bool Canary::generalAlarmRaised = false;
bool Canary::weatherAlarmRaised = false;
bool Canary::fireAlarmRaised = false;
bool Canary::chemicalAlarmRaised = false;
bool Canary::violenceAlarmRaised = false;

int Canary::raiseAllClear() {
    generalAlarmRaised  = false;
    weatherAlarmRaised  = false;
    fireAlarmRaised     = false;
    chemicalAlarmRaised = false;
    violenceAlarmRaised = false;
    return 0;
}

int Canary::raiseAlarm(int alarmType) {
    raiseAllClear();

    switch (alarmType) {
        case 0 : return 0;
        case 1 : generalAlarmRaised = true; break;
        case 2 : weatherAlarmRaised = true; break;
        case 3 : fireAlarmRaised = true; break;
        case 4 : chemicalAlarmRaised = true; break;
        case 5 : violenceAlarmRaised = true; break;
    }

    return 0;
}

int Canary::alarmRaised() {
    if (generalAlarmRaised)
        return 1;
    else if (weatherAlarmRaised)
        return 2;
    else if (fireAlarmRaised)
        return 3;
    else if (chemicalAlarmRaised)
        return 4;
    else if (violenceAlarmRaised)
        return 5;
    else
        return 0;
}
