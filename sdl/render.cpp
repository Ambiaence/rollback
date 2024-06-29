#include "../sdl.hpp"

Render::Render() {
	this->render_width = 12;
	this->screen_height = (SCREEN_HEIGHT/SCREEN_WIDTH)*render_width;
}

void Render::draw_frame(Match& match) {
	clear_screen();
	draw_player(*match.player_two);
	present_sdl();
}

ScreenPoint Render::translate_render_point_to_screen_point(float x, float y) {
	ScreenPoint screen_point;
	float horizontal_ratio = SCREEN_WIDTH/20;
	float vertical_ratio = SCREEN_HEIGHT/horizontal_ratio;

	screen_point.y = y*vertical_ratio; //Same for now

	screen_point.x = x*horizontal_ratio + (SCREEN_WIDTH/2);

	return screen_point;
}

void Render::draw_player(Player& player) {
	ScreenPoint middle_of_player = translate_render_point_to_screen_point(player.position.x, player.position.y);
	std::cout << middle_of_player.x << " " << middle_of_player.y << '\n';
	draw_rectangle(middle_of_player.x, middle_of_player.y, 20, 20);
}
