#pragma once

#include <vector>
#include <array>
#include <iostream>
#include <boost/endian/buffers.hpp> 

#define NUMBER_OF_INPUTS 7

typedef char InputIdType;
typedef boost::endian::big_int64_buf_t FrameCounterType;
typedef boost::endian::big_int64_buf_t ChangeCounterType;

struct Input { 
	InputIdType id;
	bool value;
};

typedef std::vector<Input> InputGroup;

class DeltaInputFrame {
	public:
		FrameCounterType frame_counter;
		ChangeCounterType change_counter; 
		DeltaInputFrame();
		int serialize(std::string &, std::error_code);
		int deserialize(std::string&, std::error_code);
		void add_input(InputIdType, bool);
	private:
		InputGroup inputs;
		int input_count;
};

