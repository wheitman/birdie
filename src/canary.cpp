#include "canary.h"

int Canary::mCurrentAlarm = 0; //start with no alarm
QString Canary::mTitle = "";
QString Canary::mBody = "";
char Canary::mLevel = '-';

void Canary::raiseAlarm(int alarm){
    if(alarm==mCurrentAlarm)
        return;
    mCurrentAlarm = alarm;
    emit currentAlarmChanged();
}

void Canary::changeTitle(QString title){
    emit currentAlarmChanged();
    mTitle = title;
}

void Canary::changeBody(QString body){
    emit currentAlarmChanged();
    mBody = body;
}

void Canary::setLevel(char level){
    emit currentAlarmChanged();
    qDebug("NEW LEVEL: "+QString(level).toLatin1());
    mLevel = level;
}
