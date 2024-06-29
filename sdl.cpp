#include "sdl.hpp"

SDL_Renderer* gRenderer;
SDL_Window* window;


void present_sdl() {
	SDL_RenderPresent(gRenderer);
}

void closeSDL() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	gRenderer = NULL;
	window = NULL;
	SDL_Quit();
}
void clear_screen() {
	SDL_Rect screen_rectangle = {0, 0, SCREEN_WIDTH ,SCREEN_HEIGHT};
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderFillRect( gRenderer, &screen_rectangle );
}

void draw_rectangle(int x, int y, int height, int width) {
	SDL_Rect rectangle; 
	rectangle.x = x;
	rectangle.y = y;
	rectangle.h = height;
	rectangle.w = width;
	SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderFillRect( gRenderer, &rectangle );
}

int initSDL() {
	bool success = false;
	SDL_Window* window = NULL;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		window = SDL_CreateWindow( "CHIP-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			SDL_UpdateWindowSurface( window );

			//Create renderer for window
			gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

			if( gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
			} else {
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				success = true;
			}
		}
	}

	if(not success) {
		closeSDL();
		return -1;
	}
	return success;
}
