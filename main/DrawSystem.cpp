#include "const.h"

class DrawSystem {
public:
	void static update(SDL_Renderer *renderer, entt::registry<> &registry) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		auto view = registry.view<position, shapeinfo>();
		for (auto entity : view) {
			DrawRectangle(renderer, registry, entity);
		}
		SDL_RenderPresent(renderer);
	}
};