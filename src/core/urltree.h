#pragma once

#include <cpprest/http_listener.h>
#include <functional>
#include <map>
#include <memory>
#include <string>

namespace shan
{
using HandlerFunc = std::function<void(web::http::http_request &)>;

class UrlTree
{
public:
    UrlTree();
    ~UrlTree() = default;

    void Insert(const utility::string_t &path, const HandlerFunc &function);
    HandlerFunc &Find(const utility::string_t &path);

private:
    // Name of path segment and next UrlTree
    std::map<utility::string_t, std::unique_ptr<UrlTree>> m_treeData;
    HandlerFunc m_function;
};
} // namespace shan
