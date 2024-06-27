#include "input.hpp"

void serialize_into_string(std::string & buffer, char* start_of_data, size_t length) {
	char* current_byte_p = start_of_data;

	for(int index = 0; index < length; index++) {
		buffer += *current_byte_p;
		current_byte_p++;
	}
}


DeltaInputFrame::DeltaInputFrame() {
	input_count = 0;
}

void DeltaInputFrame::add_input(InputIdType id, bool value) {
	if (inputs.size() > 6) {
		throw std::invalid_argument("There are already 7 values\n");
	}

	Input input;
	input.id = id;
	input.value = value;
	inputs.push_back(input);
}

int DeltaInputFrame::serialize(std::string & buffer, std::error_code code) {
	buffer = std::string("");

	serialize_into_string(buffer, (char*) &frame_counter, sizeof(frame_counter));
	serialize_into_string(buffer, (char*) &change_counter, sizeof(change_counter));
	for (auto input : inputs) {
		buffer += input.id;
		buffer += (char) input.value;
	}

	for(auto character : buffer) {
		std::cout << (int) character << std::endl;
	}

	return -1;
}
