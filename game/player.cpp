#include "../game.hpp"

Player::Player() {
	this->position.x = 0;
	this->position.y = 0;
}

Player::Player(float x, float y) {
	this->position.x = x;
	this->position.y = y;
}
