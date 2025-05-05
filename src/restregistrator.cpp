#include "restregistrator.h"

#include <cpprest/http_listener.h>

RestRegistrator &RestRegistrator::GetInstance()
{
    static RestRegistrator restRegistrator;
    return restRegistrator;
}

void RestRegistrator::Register(const std::string& path, const std::string& method, const std::function<void(web::http::http_request)>& handler)
{
}
