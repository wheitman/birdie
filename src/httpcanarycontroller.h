#ifndef HTTPCANARYCONTROLLER_H
#define HTTPCANARYCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class HttpCanaryController : public HttpRequestHandler
{
    Q_OBJECT
public:
    HttpCanaryController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // HTTPCANARYCONTROLLER_H
