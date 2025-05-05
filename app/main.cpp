#include <irestserver.h>
#include <memory>

int main(int argc, char **argv)
{
    shan::IRestserver::RestserverReq req = {"http://localhost", 5000};

    std::unique_ptr<shan::IRestserver> restserver(
        shan::IRestserver::Create(req));

    restserver->Run();

    return 0;
}
