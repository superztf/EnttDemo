#include "const.h"
/*
处理圆形越出边界反弹
暂时无用
*/
class BorderSystem {
public:
	void static update(std::uint64_t dt, entt::registry<> &registry) {
		registry.view<position, velocity, circleinfo>().each([dt](const auto, position &pos, velocity &vel,const circleinfo &cinfo) {
			if (pos.y + cinfo.radius >= MAP_HEIGHT && vel.dy > 0) {
				vel.dy *= -1;
			}
			if ((pos.x < cinfo.radius && vel.dx < 0) || (pos.x + cinfo.radius >= MAP_WIDTH && vel.dx > 0)) {
				vel.dx *= -1;
			}
		});
	}
};