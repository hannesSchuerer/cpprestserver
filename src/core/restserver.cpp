#include "restserver.h"

#include <sstream>
#include <string>
#include <vector>

#include "log.h"
#include "restregistrator.h"
#include "utils.h"

namespace shan
{
//------------------------------------------------------------------------------
IRestserver *IRestserver::Create(const RestserverReq &req)
{
    return new Restserver(req.host, req.port);
}
//------------------------------------------------------------------------------
Restserver::Restserver(const char *host, const std::uint16_t port)
    : m_pHost(host), m_port(port)
{
    Init();
}
//------------------------------------------------------------------------------
void Restserver::Run()
{
    bool isRunning = true;

    std::wstringstream ss;

    SHAN_LOG_INFO("Starting server on Host: {} Port: {}", m_pHost, m_port);
    ss << m_pHost << ":" << m_port;

    web::http::uri uri(ss.str());
    m_pListener =
        std::make_unique<web::http::experimental::listener::http_listener>(uri);

    m_pListener->support(
        std::bind(&Restserver::RequestHandler, this, std::placeholders::_1));

    m_pListener->open()
        .then([&]() {
            SHAN_LOG_INFO(
                "Restserver listening on: {}",
                shan::utils::ToString(m_pListener->uri().to_string()));
        })
        .wait();

    while (isRunning)
        ;
}
//------------------------------------------------------------------------------
void Restserver::Init()
{
    shan::Log::Init();
}
//------------------------------------------------------------------------------
void Restserver::RequestHandler(web::http::http_request request)
{
    SHAN_LOG_TRACE("Recieved request:\n{}\n",
                   shan::utils::ToString(request.to_string()));

    const utility::string_t path = request.relative_uri().path();

    HandlerFunc &test = RestRegistrator::GetInstance().GetHandler(
        utility::conversions::to_utf8string(path),
        "POST");

    if (!test)
    {
        SHAN_LOG_ERROR("Path or method is not defined!");

        request.reply(web::http::status_codes::NotFound,
                      "Path or method is not defined!");
        SHAN_LOG_TRACE(
            "Replied with:\n{}\n",
            utils::ToString(request.get_response().get().to_string()));
    }
    else
    {
        test(request);
    }
}
//------------------------------------------------------------------------------
} // namespace shan
