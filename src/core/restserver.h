#pragma once

#include <cpprest/http_listener.h>
#include <memory>

#include "irestserver.h"

namespace shan
{
class Restserver : public IRestserver
{
    friend IRestserver;

public:
    void Run() override;

private:
    Restserver(const char *host, const std::uint16_t port);
    ~Restserver() = default;
    void Init();
    void RequestHandler(web::http::http_request request);

private:
    std::unique_ptr<web::http::experimental::listener::http_listener>
        m_pListener;

    std::uint16_t m_port = 0;
    const char *m_pHost = nullptr;
};
} // namespace shan
