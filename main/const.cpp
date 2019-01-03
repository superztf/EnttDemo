#include"const.h"
#include <iostream>



void initshape() {
	SHAPE_INFO[ENEMY_0] = { 50,128,50,255,30,30 }; // r g b a w h
	SHAPE_INFO[ENEMY_1] = { 255,255,0,255,35,25 };
	SHAPE_INFO[ENEMY_2] = { 128,0,128,255,40,36 };
	SHAPE_INFO[PLAYER] = { 0,0,200,255,40,50 };
	SHAPE_INFO[BULLET] = { 255,193,37,255,15,15 };
}

//inline int GetShapeWidth(shapeinfo& info) {
//	return SHAPE_INFO[info.enttype][4];
//}
//
//inline int GetShapeWidth(int enttype) {
//	return SHAPE_INFO[enttype][4];
//}
//
//inline int GetShapeHeight(shapeinfo& info) {
//	return SHAPE_INFO[info.enttype][5];
//}
//
//inline int GetShapeHeight(int enttype) {
//	return SHAPE_INFO[enttype][5];
//}
//
//inline int GetPlayerWidth() {
//	return SHAPE_INFO[PLAYER][4];
//}
//
//inline int GetPlayerHeight() {
//	return SHAPE_INFO[PLAYER][5];
//}

void DrawRectangle(SDL_Renderer *&renderer, entt::registry<> &registry,ENTITY ent) {
	if (!registry.valid(ent)) {
		std::cout << "error: try an invalid entity" << std::endl;
		return;
	}
	position& pos = registry.get<position>(ent);
	shapeinfo& info = registry.get<shapeinfo>(ent);
	SDL_Rect rect = { pos.x, pos.y, GetShapeWidth(info.enttype), GetShapeHeight(info.enttype) };
	// cout << pos.x << pos.y << GetShapeWidth(info.enttype) << GetShapeHeight(info.enttype) << endl;
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, SHAPE_INFO[info.enttype][0], SHAPE_INFO[info.enttype][1], SHAPE_INFO[info.enttype][2], SHAPE_INFO[info.enttype][3]);
	SDL_RenderFillRect(renderer, &rect);
}