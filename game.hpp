#pragma once
#include <iostream>

struct Position {
	float x;
	float y;
};

class Player {
	public:
		Player();
		Player(float, float);
		Position position;
};

class Match {
	public:
		Match();
		Player* player_one;
		Player* player_two;
};
