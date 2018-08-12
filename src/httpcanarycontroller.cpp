#include "httpcanarycontroller.h"
#include "canary.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

Q_GLOBAL_STATIC(Canary, myCanary)
Q_GLOBAL_STATIC(QQmlApplicationEngine, engine)

HttpCanaryController::HttpCanaryController(QObject* parent) : HttpRequestHandler (parent)
{
    //empty
}

void HttpCanaryController::service(HttpRequest& request, HttpResponse& response){
    qDebug("CANARY ALERT");
    response.write("Request received");
    myCanary->raiseAlarm(1);

    QObject *rootObject = engine->rootObjects().first();

    QObject *button = rootObject->findChild<QObject *>("helloWorld");
    if(button){
        button->setProperty("text","DOUBLE YEET");
    }
    else {
        qDebug("not found");
    }
}
