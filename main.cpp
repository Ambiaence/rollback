#include <iostream>
#include <array>
#include "input.hpp"

void serilize(char* char_buffer, const InputState & input_state) {
	char_buffer[0] = input_state.frame;
	char_buffer[1] = input_state.left;
	char_buffer[2] = input_state.right;
	char_buffer[3] = input_state.up;
	char_buffer[4] = input_state.down;
	char_buffer[5] = input_state.a;
	char_buffer[6] = input_state.b;
}

void print_character_value(char character) {
	std::cout << (int) character << '\n';
}

int main(int argc, char* argv[]) {
	InputState input_state;
	init_input_state(input_state);
	input_state.frame = 5;
	char buffer[7];
	serilize(buffer, input_state);

	input_state.up = true;
	print_character_value(buffer[0]);
	print_character_value(buffer[1]);
	print_character_value(buffer[2]);
	print_character_value(buffer[3]);
	print_character_value(buffer[4]);
	print_character_value(buffer[5]);
	print_character_value(buffer[6]);
}
