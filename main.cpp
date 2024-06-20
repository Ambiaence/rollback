#include <iostream>
#include <string>
#include <array>
#include "input.hpp"

void print_character_value(char character) {
	std::cout << (int) character << '\n';
}

int main(int argc, char* argv[]) {
	DeltaInputFrame delta;
	std::string message;
	std::error_code error_code;

	delta.add_input(0, true);
	delta.add_input(1, true);
	delta.add_input(2, true);
	delta.add_input(3, true);

	delta.serialize(message, error_code);
	for(auto character: message) {
		std::cout << "In string " << (int) character << std::endl;
	}
}
