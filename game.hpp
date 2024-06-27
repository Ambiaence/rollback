#pragma once
#include <iostream>

struct Position {
	float x;
	float y;
};

class Player {
	public:
		Player(float, float);
		Position position;
};

class Match {
	public:
		Match();
		Player player_one(-5, 1);
		Player player_two(5, 1);
};
