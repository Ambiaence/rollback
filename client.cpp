#include <array>
#include <string>
#include <iostream>
#include <asio.hpp>
#include "input.hpp"

using asio::ip::tcp;

int main() {
	auto host = "localhost:5000";
	InputMovie input_movie;

	for (auto input_state: input_movie) {
		init_input_state(input_state);
	}

	try {
		asio::io_context io_context;
		tcp::resolver resolver(io_context);

		tcp::resolver::results_type endpoints= 
			resolver.resolve(host, "rollback");

		tcp::socket socket(io_context);
		asio::connect(socket, endpoints);
		
		for (;;) {
			InputState received_state;
			std::error_code error_code;

			size_t length =
				socket.read_some(asio::buffer(received_state), error_code);

			if (error == asio::error::eof)  {
				std::cout << "Connection closed";
				break;
			}

			if (error_code) {
				throw std::system_error(error_code);
			}
			
			std::cout << "Left = " << received_state.left << '\n';
		}



	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
