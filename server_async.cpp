#include <iostream>
#include <asio>

using namespace asio::ip::udp;

int main(){ 
	try {
		asio::io_context io_context;
		udp_server server(io_context);
		io_context.run();
	} catch( std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
