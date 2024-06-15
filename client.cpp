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

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
