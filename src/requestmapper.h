#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "httpsessionstore.h"
#include "staticfilecontroller.h"
#include "httpcanarycontroller.h"
#include "templatecache.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler
{
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static HttpSessionStore* sessionStore;
    static StaticFileController* staticFileController;
    static TemplateCache* templateCache;
private:
    HttpCanaryController httpCanaryController;
};

#endif // REQUESTMAPPER_H
