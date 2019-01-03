#include "const.h"
class SpawnEnemySystem {
public:
	void static update(std::uint64_t dt, entt::registry<> &registry) {
		auto view = registry.view<position, velocity, enemy>();
		for (auto entity : view) {
			auto[pos, vel] = view.get<position, velocity>(entity);
			if (pos.y >= MAP_HEIGHT && vel.dy > 0) {
				registry.destroy(entity);
			}
		}

		auto view2 = registry.view<position, velocity, enemy>();
		int count = view2.size();
		ENTITY e;
		while (ENEMY_CNT-count>0) {
			++count;
			const int enttype = RandomInt(ENEMY_START, ENEMY_END);
			const uint8_t width = GetShapeWidth(enttype);
			const uint8_t height = GetShapeHeight(enttype);
			e =registry.create();
			registry.assign<shapeinfo>(e, enttype);
			int posx = RandomInt(0, MAP_WIDTH - width);
			registry.assign<position>(e, posx, -height);
			registry.assign<velocity>(e, 0, 3);
			registry.assign<enemy>(e,1);
		}
	}
};