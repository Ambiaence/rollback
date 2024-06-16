#include <array>
#include <string>
#include <iostream>
#include <asio.hpp>
#include "input.hpp"

using asio::ip::tcp;

int main() {
	try {
		asio::io_context io_context;
		tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 5000));

		for(;;) {
			tcp::socket socket(io_context);
			acceptor.accept(socket);

			InputState input_state_to_send;
			init_input_state(input_state_to_send);

			std::error_code ignore_error_code;

			asio::write(asio::buffer(&input_state_to_send, sizeof(input_state_to_send)), ignore_error_code);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
