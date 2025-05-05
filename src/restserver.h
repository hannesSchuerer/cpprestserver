#pragma once

#include <memory>
#include <cpprest/http_listener.h>

namespace shan
{
	class Restserver
	{
	public:
		Restserver();
		~Restserver() = default;

		void Run();

	private:
		void Init();
		void RequestHandler(web::http::http_request request);

	private:
		std::unique_ptr<web::http::experimental::listener::http_listener> m_pListener;
	};
}
