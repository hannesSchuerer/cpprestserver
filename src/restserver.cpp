#include "restserver.h"

#include <string>
#include <vector>

//------------------------------------------------------------------------------
Restserver::Restserver()
{
    Init();
}
//------------------------------------------------------------------------------
void Restserver::Run()
{
    bool isRunning = true;

    while (isRunning)
        ;
}
//------------------------------------------------------------------------------
void Restserver::Init()
{
    web::http::uri uri(L"http://localhost:4010/");
    m_pListener = std::make_unique<web::http::experimental::listener::http_listener>(uri);

    m_pListener->support(std::bind(&Restserver::RequestHandler, this, std::placeholders::_1));

    m_pListener->open().wait();
}
//------------------------------------------------------------------------------
void Restserver::RequestHandler(web::http::http_request request)
{
    const std::wstring test = request.relative_uri().to_string().c_str();

    std::wcout << L"Request: " << request.to_string() << "\n";

    const utility::string_t &path = request.relative_uri().path();
    const web::http::method method = request.method();

    const std::vector<utility::string_t> splittedPath = web::uri::split_path(path);

    for (const auto &split : splittedPath)
        std::cout << split.c_str() << std::endl;

    request.reply(web::http::status_codes::OK);
}
//------------------------------------------------------------------------------