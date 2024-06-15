#include <array>
#include <string>
#include <iostream>
#include <asio.hpp>
#include "input.hpp"

using asio::ip:tcp;

int main() {
	host = "localhost:5000";
	try {
		asio::io_context io_context;
		tcp::resolver resolver(io_context);

		tcp::resolver::results_type endpoints= 
			resolver.resolve(host, "rollback");

		asio::socket socket(io_context);
		asio::connect(socket, endpoints);

			
	

	} catch (std::exception& e) {

	}
}

}
