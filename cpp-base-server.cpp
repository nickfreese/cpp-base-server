#include <string>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#  define CPPHTTPLIB_OPENSSL_SUPPORT
#endif
#include "httplib.h"

httplib::Server svr;
int main(int argc, char* argv[]){

	int serverPort = 8108;

    std::string curArg = "";
    std::string cli_delimiter = "=";
    for (int i = 1; i < argc; ++i) {
        curArg = argv[i];
        std::string token = curArg.substr(0, curArg.find(cli_delimiter));
        
        //grab our cli values
        if (token == "p" || token == "port") {
            serverPort = stoi(curArg.substr(curArg.find(cli_delimiter) + 1));
        }
    }

    /*
    * define our routes
    */
    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });
    
    svr.Get("/test", [&](const httplib::Request &req, httplib::Response &res) {
        json resp = {};
    	resp["message"] = "This is a response message";
        res.set_content(resp.dump(4), "application/json; charset=utf-8");
    });

    svr.Get("/get-name", [&](const httplib::Request &req, httplib::Response &res) {
  	    auto name = req.get_param_value("name");
        json resp = {};
  	    resp["name"] = name;
        res.set_content(resp.dump(4), "application/json; charset=utf-8");
  	});
    
    std::cout << "\nlistening on port " << std::to_string(serverPort) << std::endl;
    svr.listen("0.0.0.0", serverPort);

}