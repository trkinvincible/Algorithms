#ifndef BOOST_ASIO_H
#define BOOST_ASIO_H
#include "command.h"
//#include <boost/beast/core.hpp>
//#include <boost/beast/http.hpp>
//#include <boost/beast/version.hpp>
//#include <boost/asio/connect.hpp>
//#include <boost/asio/ip/tcp.hpp>
//#include <cstdlib>
//#include <iostream>
//#include <string>
//#include <iostream>
//#include <istream>
//#include <ostream>
//#include <string>
//#include <boost/asio.hpp>

//namespace beast = boost::beast;     // from <boost/beast.hpp>
//namespace http = beast::http;       // from <boost/beast/http.hpp>
//namespace net = boost::asio;        // from <boost/asio.hpp>
//using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>

    class boost_asio: public Command{

        void execute(){

//        try
//        {
//            //https://jsonmock.hackerrank.com/api/movies/search/?Title=Ave
//            //auto const host = "www.example.com";
//            auto const host = "jsonmock.hackerrank.com";
//            //const auto target = "/";//"/api/movies/search/";
//            const auto target = "/api/movies/search";
//            auto const version = 10;
//            const auto port="443";

//            // The io_context is required for all I/O
//            net::io_context ioc;

//            // These objects perform our I/O
//            tcp::resolver resolver{ioc};
//            tcp::socket socket{ioc};

//            // Look up the domain name
//            tcp::resolver::query query(host,port);
//            auto const results = resolver.resolve(query);

//            // Make the connection on the IP address we get from a lookup
//            net::connect(socket, results.begin(), results.end());

//            // Set up an HTTP GET request message
//            http::request<http::string_body> req{http::verb::get,target,version};
//            req.set(http::field::host, host);
//            req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

//            beast::error_code ec;

//            // Send the HTTP request to the remote host
//            http::write(socket, req,ec);

//            // This buffer is used for reading and must be persisted
//            beast::flat_buffer buffer;

//            // Declare a container to hold the response
//            http::response<http::dynamic_body> res;

//            // Receive the HTTP response
//            std::cout << http::read(socket, buffer, res,ec) << std::endl;

//            // Write the message to standard out
//            std::cout << res << std::endl;

//            // Gracefully close the socket

//            socket.shutdown(tcp::socket::shutdown_both, ec);

//            // not_connected happens sometimes
//            // so don't bother reporting it.
//            //
//            if(ec && ec != beast::errc::not_connected)
//                throw beast::system_error{ec};

//            // If we get here then the connection is closed gracefully
//        }
//        catch(std::exception const& e)
//        {
//            std::cerr << "Error: " << e.what() << std::endl;
//        }
    }
};
#endif // BOOST_ASIO_H
