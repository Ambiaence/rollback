#include "input.hpp"

void init_input_state(InputState& input_state) {
	input_state.left = false;
	input_state.right = false;
	input_state.down = false;
	input_state.up = false;
	input_state.a = false;
	input_state.b = false;
}
