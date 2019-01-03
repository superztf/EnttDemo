#pragma once
#include <SDL/SDL.h>
#include <unordered_map>
#include <entt/entt.hpp>
#include "circleinfo.h"
#include "position.h"
#include "shapeinfo.h"
#include "velocity.h"
#include "event.h"
#include "lastbullet.h"
#include "enemy.h"
#include "owner.h"
#include <time.h>
#include <iostream>
using namespace std;

#define MAP_HEIGHT 960
#define MAP_WIDTH 540
#define CircleDistance(x1, y1, x2, y2) ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define IsCircleCollision(pos1, pos2, info1, info2) ((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y) < (info1.radius + info2.radius) * (info1.radius + info2.radius))
#define RandomInt(a, b) (rand() % (b - a - 1)) + a + 1;

const clock_t MS_PER_F = 16;
const uint8_t ENEMY_CNT = 6;

typedef uint32_t ENTITY;

enum SHAPE_TYPE
{
	ENEMY_START,
	ENEMY_0,
	ENEMY_1,
	ENEMY_2,
	ENEMY_END,
	PLAYER,
	BULLET,
};

void initshape();
void DrawRectangle(SDL_Renderer *&renderer, entt::registry<> &registry, ENTITY ent);

static std::unordered_map<int, std::vector<int>> SHAPE_INFO;

inline int GetShapeWidth(shapeinfo &info)
{
	return SHAPE_INFO[info.enttype][4];
}

inline int GetShapeWidth(int enttype)
{
	return SHAPE_INFO[enttype][4];
}

inline int GetShapeHeight(shapeinfo &info)
{
	return SHAPE_INFO[info.enttype][5];
}

inline int GetShapeHeight(int enttype)
{
	return SHAPE_INFO[enttype][5];
}

bool SDLInit(SDL_Window *&window, SDL_Renderer *&renderer);
void SDLDestroy(SDL_Window *window, SDL_Renderer *renderer);
void WorldInit(entt::registry<> &registry);
ENTITY GetPlayer();