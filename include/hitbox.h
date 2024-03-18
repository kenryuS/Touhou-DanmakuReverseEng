#ifndef HITBOX_H_
#define HITBOX_H_

#include <raylib.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

typedef enum Hitbox_e {
    HB_CIRCLE = 1,
    HB_RECT,
    HB_LINE
} Hitbox_e;

typedef struct {
    float radius;
    Vector2 center;
} Hitbox_Circle;

typedef struct {
    Vector2 pos;
    Vector2 size;
} Hitbox_Rect;

typedef struct {
    Vector2 start;
    Vector2 end;
} Hitbox_Line;

typedef union {
    Hitbox_Circle circle;
    Hitbox_Rect rect;
    Hitbox_Line line;
} Hitbox_u;

typedef struct {
    Hitbox_u core;
    Hitbox_e type;
} Hitbox;

bool isCollided(Hitbox h1, Hitbox h2);

void hitbox_render(Hitbox target);

bool CheckCollisionLineCircle(Vector2 startPos, Vector2 endPos, Vector2 center, float radius);

bool CheckCollisionLineRect(Vector2 startPos, Vector2 endPos, Rectangle rect);

#endif // !HITBOX_H_
