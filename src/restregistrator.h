#pragma once

#include <functional>
#include <string>

namespace web
{
namespace http
{
class http_request;
namespace experimental
{
namespace listener
{
class http_listener;
}
} // namespace experimental
} // namespace http
} // namespace web
class RestRegistrator
{
public:
    static RestRegistrator &GetInstance();

    void Register(const std::string &path,
                  const std::string &method,
                  const std::function<void(web::http::http_request)> &handler);

private:
    RestRegistrator() = default;
    ~RestRegistrator() = default;
};