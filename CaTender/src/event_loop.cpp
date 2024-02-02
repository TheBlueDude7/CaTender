#include "event_loop.hpp"
#include "mouse.hpp"

void event_loop() {
	SDL_Event e;
	bool exit = false;

	Mouse mouse(e);

	while (!exit) {
		// handle polled events
		while (SDL_PollEvent(&e) != 0) {
			uint32_t type = e.type;
			
			switch (type) {
			case SDL_QUIT:
				exit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEMOTION:
				mouse.update_mouse();
				break;
			}
		}
	}
}
