#include "httpcanarycontroller.h"
#include "canary.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

HttpCanaryController::HttpCanaryController(QObject* parent) : HttpRequestHandler (parent)
{
    //empty
}

void HttpCanaryController::service(HttpRequest& request, HttpResponse& response){
    qDebug("CANARY ALERT");
    response.write("Request received");
    Canary *myCanary = new Canary();
    myCanary->raiseAlarm(1);
}
