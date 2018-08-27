#include "httpcanarycontroller.h"
#include "canary.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include "birdieqttools.h"

HttpCanaryController::HttpCanaryController(QObject* parent) : HttpRequestHandler (parent)
{

}

void HttpCanaryController::service(HttpRequest& request, HttpResponse& response){
    qDebug("CANARY ALERT");
    response.write("Request received");
    BirdieQtTools::setQmlProperty("canary","currentAlarm","0");
}
