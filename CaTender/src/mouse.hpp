#pragma once
#include <SDL.h>

class Mouse {
public:

	enum MOUSEBUTTONDIR {
		LEFT,
		RIGHT
	};

	Mouse(SDL_Event &e);

	int get_x();
	int get_y();

	bool mouse_up(MOUSEBUTTONDIR dir);
	bool mouse_down(MOUSEBUTTONDIR dir);

	bool left_mouse_down();
	bool right_mouse_up();
	bool left_mouse_up();
	bool right_mouse_down();


	void update_mouse();
private:
	SDL_Event& m_e;
	int x;
	int y;
	bool left_mouse_pressed;
	bool right_mouse_pressed;
};