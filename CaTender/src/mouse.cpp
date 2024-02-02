#include "mouse.hpp"

Mouse::Mouse(SDL_Event& e) : m_e(e), y(0), x(0), left_mouse_pressed(false), right_mouse_pressed(false) {
}

int Mouse::get_x() {
	return x;
}

int Mouse::get_y() {
	return y;
}

// enum-switched mouse events
bool Mouse::mouse_down(MOUSEBUTTONDIR dir) {
	if (dir == MOUSEBUTTONDIR::LEFT) {
		return left_mouse_pressed;
	}
	else if (dir == MOUSEBUTTONDIR::RIGHT) {
		return right_mouse_pressed;
	}
	return false;
}

bool Mouse::mouse_up(MOUSEBUTTONDIR dir) {
	if (dir == MOUSEBUTTONDIR::LEFT) {
		return !left_mouse_pressed;
	}
	else if (dir == MOUSEBUTTONDIR::RIGHT) {
		return !right_mouse_pressed;
	}
	return false;
}

// manual check mouse events
bool Mouse::left_mouse_up() {
	return !left_mouse_pressed;
}

bool Mouse::left_mouse_down() {
	return left_mouse_pressed;
}

bool Mouse::right_mouse_up() {
	return !right_mouse_pressed;
}

bool Mouse::right_mouse_down() {
	return right_mouse_pressed;
}

void Mouse::update_mouse() {

	SDL_GetMouseState(&x, &y);
	
	// Update state of the mouse buttons
	if (m_e.type == SDL_MOUSEBUTTONDOWN) {
		if (m_e.button.button == SDL_BUTTON_LEFT) {
			left_mouse_pressed = true;
		} else {
			// if not left click, assume right click
			right_mouse_pressed = true;
		}
	} else if (m_e.type == SDL_MOUSEBUTTONUP) {
		if (m_e.button.button == SDL_BUTTON_LEFT) {
			left_mouse_pressed = false;
		} else {
			right_mouse_pressed = false;
		}
	}
}


