#include "httpcanarycontroller.h"
#include "canary.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include "birdieqttools.h"

Q_GLOBAL_STATIC(Canary, myCanary)
Q_GLOBAL_STATIC(QQmlApplicationEngine, engine)

HttpCanaryController::HttpCanaryController(QObject* parent) : HttpRequestHandler (parent)
{
    //empty
}

void HttpCanaryController::service(HttpRequest& request, HttpResponse& response){
    qDebug("CANARY ALERT");
    response.write("Request received");
    BirdieQtTools::setQmlProperty("helloWorld","text","ALERT");
}
