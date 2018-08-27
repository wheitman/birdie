#ifndef HTTPMANIFESTCONTROLLER_H
#define HTTPMANIFESTCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class httpmanifestcontroller : public HttpRequestHandler
{
    Q_OBJECT

public:
    httpmanifestcontroller(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // HTTPMANIFESTCONTROLLER_H
