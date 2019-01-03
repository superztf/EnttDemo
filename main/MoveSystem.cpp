#include "const.h"

class MoveSystem {
public:
	void static update(int dt, entt::registry<> &registry) {
		registry.view<position, velocity>().each([dt](const auto, position &pos, velocity &vel) {
			pos.x += vel.dx * dt / MS_PER_F;
			pos.y += vel.dy * dt / MS_PER_F;
		});
	}
};

