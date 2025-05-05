#include "utils.h"

#include <cpprest/asyncrt_utils.h>

namespace shan 
{
    namespace utils
    {
        std::string ToString(const std::wstring& str)
        {
            return utility::conversions::to_utf8string(str);
        }
    }
}
