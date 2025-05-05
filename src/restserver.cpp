#include "restserver.h"

#include <string>
#include <sstream>
#include <vector>

#include "log.h"
#include "utils.h"

namespace shan
{
	//------------------------------------------------------------------------------
	Restserver::Restserver()
	{
		Init();
	}
	//------------------------------------------------------------------------------
	void Restserver::Run()
	{
		bool isRunning = true;

		std::wstringstream ss;

		const int port = 4010;
		const char* host = "localhost";

		SHAN_LOG_INFO("Starting server on Host: {} Port: {}", host, port);
		ss << "http://" << host << ":" << port;

		web::http::uri uri(ss.str());
		m_pListener = std::make_unique<web::http::experimental::listener::http_listener>(uri);

		m_pListener->support(std::bind(&Restserver::RequestHandler, this, std::placeholders::_1));

		m_pListener->open().then([&]() {
			SHAN_LOG_INFO("Restserver listening on: {}", shan::utils::ToString(m_pListener->uri().to_string()));
			}).wait();

		while (isRunning)
			;
	}
	//------------------------------------------------------------------------------
	void Restserver::Init()
	{
		shan::Log::Init();
	}
	//------------------------------------------------------------------------------
	void Restserver::RequestHandler(web::http::http_request request)
	{
		SHAN_LOG_INFO("Recieved request:\n{}\n", shan::utils::ToString(request.to_string()));

		const utility::string_t& path = request.relative_uri().path();
		const std::vector<utility::string_t> splittedPath = web::uri::split_path(path);

		for (const auto& split : splittedPath)
			std::cout << split.c_str() << std::endl;

		request.reply(web::http::status_codes::OK);
		SHAN_LOG_INFO("Replied with:\n{}\n", shan::utils::ToString(request.get_response().get().to_string()));
	}
	//------------------------------------------------------------------------------
}
