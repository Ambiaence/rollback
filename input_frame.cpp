#include "input.hpp"

Inputframe_number::InputFrame() {
	this->input_state = InputState();
	this->frame_number = 0;
}

Inputframe_number::InputFrame(FrameCounter frame) {
	this->input_state = InputState();
	this->frame_number = frame;
}

Inputframe_number::InputFrame(FrameCounter frame, InputState input_state) {
	this->input_state = input_state;
	this->frame_number = frame;
}
