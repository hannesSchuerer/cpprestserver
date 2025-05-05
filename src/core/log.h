#pragma once

#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace shan
{
class Log
{
public:
    static void Init();
    static std::shared_ptr<spdlog::logger> GetLog();

private:
    Log() = default;

private:
    static std::shared_ptr<spdlog::logger> s_pLogger;
};
} // namespace shan

#define SHAN_LOG_TRACE(...) shan::Log::GetLog()->trace(__VA_ARGS__)
#define SHAN_LOG_INFO(...) shan::Log::GetLog()->info(__VA_ARGS__)
#define SHAN_LOG_WARN(...) shan::Log::GetLog()->warn(__VA_ARGS__)
#define SHAN_LOG_ERROR(...) shan::Log::GetLog()->error(__VA_ARGS__)
