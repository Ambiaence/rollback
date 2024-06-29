#pragma once
#include <SDL2/SDL.h>
#include "game.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 320;

void closeSDL();
void draw_rectangle(int,int,int,int);
void present_sdl();
void clear_screen();
void render();
void sdlDrawScreen(unsigned char screen[32][8]);
int initSDL();

struct ScreenPoint {
	int x;
	int y;
};

class Render {
	public:
		Render();
		void draw_frame(Match&);

	private:
		float render_width;
		float screen_height;

		ScreenPoint translate_render_point_to_screen_point(float, float);

		void draw_player(Player&);

};
