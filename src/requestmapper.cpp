#include "requestmapper.h"
#include <QQmlApplicationEngine>
#include "httpcanarycontroller.h"
#include "fileuploadcontroller.h"

HttpSessionStore* RequestMapper::sessionStore=0;
StaticFileController* RequestMapper::staticFileController=0;
TemplateCache* RequestMapper::templateCache=0;

RequestMapper::RequestMapper(QObject* parent) : HttpRequestHandler (parent)
{
    qmlRegisterType<HttpCanaryController>("com.birdie.canary",1,0,"HttpCanaryController");
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response){
    QByteArray path = request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if(path=="/canary") {
        httpCanaryController.service(request, response);
    }
    else if (path.startsWith("/slides")){
        staticFileController->service(request,response);
    }
    else if (path=="/upload"){
        FileUploadController().service(request,response);
    }
    else {
        response.setStatus(404, "Not found");
        response.write("We couldn't retrieve the URL you asked for.",true);
    }

    qDebug("RequestMapper: finished request");
}
