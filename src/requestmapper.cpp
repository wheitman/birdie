#include "requestmapper.h"

HttpSessionStore* RequestMapper::sessionStore=0;
StaticFileController* RequestMapper::staticFileController=0;

RequestMapper::RequestMapper(QObject* parent) : HttpRequestHandler (parent)
{
    //empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response){
    QByteArray path = request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if(path=="/canary") {
        httpCanaryController.service(request, response);
    }
    else {
        response.setStatus(404, "Not found");
        response.write("We couldn't retrieve the URL you asked for.",true);
    }

    qDebug("RequestMapper: finished request");
}
