#include "const.h"
#include <unordered_set>

class RectCollisionSystem {
public:
	void static update(int dt, entt::registry<> &registry) {
		auto bullets = registry.persistent_view<position, owner>();
		auto enemies = registry.persistent_view<position,shapeinfo, enemy>();
		unordered_set<ENTITY> removes;

		for (auto enemy : enemies) {
			if (removes.find(enemy)!=removes.end()||!registry.valid(enemy)) {
				continue;
			}
			for (auto bullet : bullets) {
				if (removes.find(bullet) != removes.end() || !registry.valid(bullet)) {
					continue;
				}
				auto pos1 = registry.get<position>(enemy);
				auto pos2 = registry.get<position>(bullet);
				auto shape1 = registry.get<shapeinfo>(enemy);
				const int width1 = GetShapeWidth(shape1.enttype);
				const int height1 = GetShapeHeight(shape1.enttype);
				const int width2 = GetShapeWidth(BULLET);
				const int height2 = GetShapeHeight(BULLET);
				if (pos2.x+width2 >= pos1.x&&pos2.x <= pos1.x + width1) {
					if (pos2.y+height2 >= pos1.y&&pos2.y <= pos1.y + height1) {
						removes.insert(bullet);
						removes.insert(enemy);
					}
				}
			}
		}

		for (ENTITY e : removes) {
			registry.destroy(e);
		}
	}
};

