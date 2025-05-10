#include <cpprest/http_listener.h>
#include <iostream>
#include <irestserver.h>
#include <memory>
#include <restregistrator.h>

void TestHandlerFunc(web::http::http_request request)
{
    std::cout << "Hello from TestHandlerFunc \n";

    request.reply(web::http::status_codes::OK);
}

int main(int argc, char **argv)
{
    shan::IRestserver::RestserverReq req = {"http://localhost", 5000};

    std::unique_ptr<shan::IRestserver> restserver(
        shan::IRestserver::Create(req));

    shan::RestRegistrator::GetInstance().Register("/test/path/12323",
                                                  "POST",
                                                  &TestHandlerFunc);

    restserver->Run();

    return 0;
}
