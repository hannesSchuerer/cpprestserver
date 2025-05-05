#include "log.h"

namespace shan
{
	std::shared_ptr<spdlog::logger> Log::s_pLogger;

	//-------------------------------------------------------------------------------
	void Log::Init()
	{
		s_pLogger = spdlog::stdout_color_mt("restserver");
		s_pLogger->set_level(spdlog::level::trace);
		s_pLogger->set_pattern("%d-%m-%Y %T #%t [%^%l%$]: %v");
	}
	//-------------------------------------------------------------------------------
	std::shared_ptr<spdlog::logger> Log::GetLog()
	{
		return s_pLogger;
	}
	//-------------------------------------------------------------------------------
}

