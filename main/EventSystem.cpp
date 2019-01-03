#include "const.h"

class EventSystem
{
public:
	void static update(int dt, entt::registry<> &registry) {
		SDL_Event event;
		if (SDL_PollEvent(&event)&& event.type == SDL_KEYDOWN) {
			const ENTITY pid = GetPlayer();
			position& pos = registry.get<position>(pid);
			int w;
			
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				pos.x -= 4;
				if (pos.x < 0) {
					pos.x = 0;
				}
				break;
			case SDLK_RIGHT:
				pos.x += 4;
				w = MAP_WIDTH - GetShapeWidth(PLAYER);
				if (pos.x > w) {
					pos.x = w;
				}
				break;
			default:
				break;
			}
		}
	}
};

