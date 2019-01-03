#include "const.h"

class BulletSystem {
public:
	void static update(std::uint64_t dt, entt::registry<> &registry) {
		const ENTITY pid = GetPlayer();
		if (!registry.has<lastbullet>(pid)) {
			createbullet(registry,pid);
			return;
		}
		ENTITY bulletid = registry.get<lastbullet>(pid).id;
		if (!registry.valid(bulletid)) {
			registry.remove<lastbullet>(pid);
			createbullet(registry, pid);
			return;
		}
		const position pos = registry.get<position>(bulletid);
		const int bulletheight = GetShapeHeight(BULLET);
		const int playerheight = GetShapeHeight(PLAYER);
		if (MAP_HEIGHT-pos.y - bulletheight - playerheight >= bulletheight+10) {
			createbullet(registry, pid);
		}
		
		auto view = registry.view<position, velocity, owner>();
		for (auto entity : view) {
			auto[pos, vel] = view.get<position, velocity>(entity);
			if (pos.y <=0 && vel.dy < 0) {
				registry.destroy(entity);
			}
		}
	}

	void static createbullet(entt::registry<> &registry, ENTITY pid) {
		const position pos = registry.get<position>(pid);
		const int playerwidth = GetShapeWidth(PLAYER);
		const int bulletwidth = GetShapeWidth(BULLET);
		const int bulletheight = GetShapeHeight(BULLET);
		int posx = pos.x + playerwidth / 2 - bulletwidth / 2;
		int posy = pos.y + bulletheight;
		const ENTITY e= registry.create();
		registry.assign<position>(e,posx,posy);
		registry.assign<velocity>(e, 0,-5);
		registry.assign<shapeinfo>(e, BULLET);
		registry.assign<owner>(e, pid);
		if (!registry.has<lastbullet>(pid)) {
			registry.assign<lastbullet>(pid, e);
		}
		else {
			registry.replace<lastbullet>(pid, e);
		}
	}
};