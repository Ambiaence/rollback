#include <iostream>
#include <string>
#include <array>
#include "sdl.hpp"
#include "input.hpp"

void print_character_value(char character) {
	std::cout << (int) character << '\n';
}

int main(int argc, char* argv[]) {
		
	SDL_Event sdl_event;
	int sdl_error = initSDL();
	bool run = true;

	if (sdl_error == -1) {
		std::cout << "Something went wrong with sdl - Ambiaence. " << std::endl;
		return -1;
	}

	while(run) {
		while(SDL_PollEvent( &sdl_event ) != 0 ) {
			if( sdl_event.type == SDL_QUIT ) {
				run = false;
			}
		}
	}

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
