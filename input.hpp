#pragma once
#include <array>


typedef unsigned int FrameCounter;

struct InputState {
		FrameCounter frame;
		bool left;
		bool right;
		bool up;
		bool down;
		bool a;
		bool b;
};

typedef std::array<InputState, 300> InputMovie;

void init_input_state(InputState& input_state);
