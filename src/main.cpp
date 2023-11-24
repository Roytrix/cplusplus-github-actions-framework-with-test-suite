#include <pistache/endpoint.h>

using namespace Pistache;

struct helloHandler : public Http::Handler {
    HTTP_PROTOTYPE(helloHandler)
    void onRequest(const Http::Request&, Http::ResponseWriter writer) override {
    writer.send(Http::Code::Ok, "Hello, World with pistache! options test");
    }
};

int main(){

    // Set the restapi options
    auto opts = Http::Endpoint::options();
    opts.flags(Tcp::Options::ReuseAddr);
    opts.flags(Tcp::Options::ReusePort);
    Http::listenAndServe<helloHandler>(Pistache::Address("*:9080"),opts);
}