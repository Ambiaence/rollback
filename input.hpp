#include <array>

typedef unsigned int FrameCounter;

class InputState {
	public:
		InputState();

		bool left;
		bool right;
		bool up;
		bool down;
		bool a;
		bool b;
};

class InputFrame {
	public:
		InputFrame();
		InputFrame(FrameCounter);
		InputFrame(FrameCounter, InputState);

		InputState input_state;
		FrameCounter frame_number;
};

class InputMovie {
	public:
		InputMovie();
		std::array<InputFrame, 300> input_frames;
};
