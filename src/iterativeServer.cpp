#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string makeDaytimeString() {
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 13));
        for (;;) { //iterative server
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::string message = makeDaytimeString();
            boost::system::error_code ignored_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}