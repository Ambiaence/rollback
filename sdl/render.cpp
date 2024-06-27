#include "../sdl.hpp"

Render::Render() {
	this->render_width = 12;
	this->screen_height = (SCREEN_HEIGHT/SCREEN_WIDTH)*render_width;
}

void Render::draw_frame(Match& match) {
	draw_player(match.player_one);
	draw_player(match.player_two);
}

ScreenPoint translate_render_point_to_screen_point(float x, float y) {
	ScreenPoint screen_point;
	screen_point.y = y; //Same for now

	float ratio = SCREEN_WIDTH/x;
	screen_point.x = x*ratio + (SCREEN_WIDTH/2);

	return screen_point;
}

void Render::draw_player(Player& player) {
	ScreenPoint middle_of_player = translate_render_point_to_screen_point(player.position.x, player.position.y);
	draw_rectangle(middle_of_player.x, middle_of_player.y, 10, 10);
}
