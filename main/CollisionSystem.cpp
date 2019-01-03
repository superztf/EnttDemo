#include <cstdint>
#include "const.h"

/*
圆形完全弹性碰撞
暂时无用
*/
class CollisionSystem {
public:
	void static update(int dt, entt::registry<> &registry) {
		auto view = registry.view<position, velocity, circleinfo>();
		for (auto entity1 : view) {
			for (auto entity2 : view) {
				if (entity1 == entity2) {
					continue;
				}
				auto [pos1, vel1, info1] = view.get<position, velocity, circleinfo>(entity1);
				auto [pos2, vel2, info2] = view.get<position, velocity, circleinfo>(entity2);
				if (!IsCircleCollision(pos1, pos2,info1,info2)) {
					continue;
				}
				const int current_dis = CircleDistance(pos1.x,pos1.y,pos2.x,pos2.y);
				const int preview_dis = CircleDistance(pos1.x+vel1.dx*dt, pos1.y+vel1.dy*dt, pos2.x+vel2.dx*dt, pos2.y+vel2.dy*dt);
				if (preview_dis < current_dis) {
					const int ma = info1.radius * info1.radius;
					const int mb = info2.radius * info2.radius;
					const int ovx1 = vel1.dx;
					const int ovy1 = vel1.dy;
					const int ovx2 = vel2.dx;
					const int ovy2 = vel2.dy;
					const int totalm = ma + mb;

					vel1.dx = ((ma - mb) * ovx1 + 2 * mb * ovx2) / totalm;
					vel1.dy = ((ma - mb) * ovy1 + 2 * mb * ovy2) / totalm;
					vel2.dx = ((mb - ma) * ovx2 + 2 * ma * ovx1) / totalm;
					vel2.dy = ((mb - ma) * ovy2 + 2 * ma * ovy1) / totalm;
				}
			}
		}
	}
};