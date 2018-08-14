#include "canary.h"

int Canary::mCurrentAlarm = 0; //start with no alarm

void Canary::raiseAlarm(int alarm){
    if(alarm==mCurrentAlarm)
        return;
    mCurrentAlarm = alarm;
    emit currentAlarmChanged();
}
