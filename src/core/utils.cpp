#include "utils.h"

namespace shan
{
namespace utils
{
//------------------------------------------------------------------------------
std::string ToString(const std::wstring &str)
{
    return utility::conversions::to_utf8string(str);
}
//------------------------------------------------------------------------------
void RemoveFirstPathSegment(utility::string_t &path)
{
    if (path.empty())
        return;

    std::size_t seperationPos = path.find('/');
    if (seperationPos == std::string::npos)
        return;

    path.replace(seperationPos, seperationPos + 1, L"");

    seperationPos = path.find('/');
    if (seperationPos == std::string::npos)
        return;

    path.replace(0, seperationPos, L"");
}
//------------------------------------------------------------------------------
}
}
