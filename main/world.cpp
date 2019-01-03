#include "BorderSystem.cpp"
#include "CollisionSystem.cpp"
#include "MoveSystem.cpp"

ENTITY g_Player = 0;

ENTITY GetPlayer() {
	return g_Player;
}

void WorldInit(entt::registry<> &registry) {
	g_Player = registry.create();
	registry.assign<position>(g_Player, (MAP_WIDTH / 2), MAP_HEIGHT-GetShapeHeight(PLAYER));
	// registry.assign<position>(g_Player, 140, 320);
	registry.assign<shapeinfo>(g_Player,PLAYER);
}


