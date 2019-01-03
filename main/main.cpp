#include "const.h"
#include <thread>
#include "DrawSystem.cpp"
#include "EventSystem.cpp"
#include "MoveSystem.cpp"
#include "SpawnEnemySystem.cpp"
#include "BulletSystem.cpp"
#include "RectCollisionSystem.cpp"

void RunGame(SDL_Renderer *renderer, entt::registry<> &registry);


int main(int argc, char* argv[]) {
	initshape();
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDLInit(window, renderer);

	entt::registry registry;
	
	WorldInit(registry);

	RunGame(renderer,registry);
	SDLDestroy(window, renderer);
	
	return 0;
}


void RunGame(SDL_Renderer *renderer, entt::registry<> &registry)
{
	clock_t dt=0;
	clock_t LAST_UPDATE = 0;
	clock_t NOW=0;

	while (true)
	{
		SpawnEnemySystem::update(dt, registry);
		EventSystem::update(dt, registry);
		BulletSystem::update(dt, registry);
		MoveSystem::update(dt, registry);
		RectCollisionSystem::update(dt, registry);
		DrawSystem::update(renderer, registry);

		NOW = clock();
		dt = NOW - LAST_UPDATE;
		if (dt < MS_PER_F) {
			std::this_thread::sleep_for(std::chrono::milliseconds(MS_PER_F -dt));
		}
		NOW = clock();
		dt = NOW - LAST_UPDATE;
		LAST_UPDATE = NOW;
	}
}
