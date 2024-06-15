#include "input.hpp"

InputMovie::InputMovie() {
	auto count = 0;
	for(auto index: this->input_frames) {
		index.frame_number = count;	
		count++;
	}
}
