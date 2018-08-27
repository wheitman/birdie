#include "httpmanifestcontroller.h"

httpmanifestcontroller::httpmanifestcontroller(QObject* parent) : HttpRequestHandler (parent)
{

}

void httpmanifestcontroller::service(HttpRequest& request, HttpResponse& response){
    //qDebug("Manifest request received");
    response.write("{}");
}
