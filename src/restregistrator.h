#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>

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
}
}
}

namespace shan
{
class UrlTree;
using HandlerFunc = std::function<void(web::http::http_request &)>;

class RestRegistrator
{
public:
    RestRegistrator(const RestRegistrator &restRegistrator) = delete;

    static RestRegistrator &GetInstance();

    void Register(const std::string &path,
                  const std::string &method,
                  const HandlerFunc &handler);

    HandlerFunc &GetHandler(const std::string &path, const std::string &method);

private:
    RestRegistrator() = default;
    ~RestRegistrator() = default;

    // This Method will be returned if the Path or the Method wasn't implemented
    void PathNotFound(web::http::http_request &request);

    HandlerFunc m_currentHandler;

private:
    // Method and UrlTree
    std::map<std::string, std::unique_ptr<UrlTree>> m_treeData;
};
}
