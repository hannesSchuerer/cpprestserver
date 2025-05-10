#pragma once

#include <cpprest/http_listener.h>

namespace shan
{
namespace utils
{
std::string ToString(const std::wstring &str);
void RemoveFirstPathSegment(utility::string_t &path);
}
} // namespace shan
