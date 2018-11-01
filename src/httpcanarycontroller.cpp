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
    response.write("{\"status\":\"success\"}");
    Canary c;
    BirdieQtTools::setQmlProperty("canary","currentAlarm",request.getParameter("type"));
    BirdieQtTools::setQmlProperty("canary","body",request.getParameter("body"));
    BirdieQtTools::setQmlProperty("canary","title",request.getParameter("title"));

    try {
        c.setLevel(request.getParameter("level").at(0));
    }catch(const std::exception&){
        qWarning("HttpCanaryController: setLevel error");
    }
}
