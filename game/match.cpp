#include "../game.hpp"

Match::Match() {
	this->player_one = new Player(-5, 1); 
	this->player_two = new Player(5, 1); 
}
