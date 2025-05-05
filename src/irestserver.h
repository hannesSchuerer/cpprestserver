#pragma once

#include <cstdint>

namespace shan
{
class IRestserver
{
public:
    struct RestserverReq
    {
        char *host = nullptr;
        std::uint16_t port = 4000;
    };

public:
    static IRestserver *Create(const RestserverReq &req);
    virtual void Run() = 0;
    virtual ~IRestserver() = default;

protected:
    IRestserver() = default;
};
} // namespace shan