#ifndef BOSS_H_
#define BOSS_H_

#include <raylib.h>
#include <stdio.h>
#include "config.h"
#include "util.h"
#include "sprite-base.h"
#include "hitbox.h"

typedef struct {
    Sprite core;
    char* name;
    int lives;
    float health;
} BossSprite;

typedef enum {
    TEST = 1
} Bosses;

BossSprite boss_init(char* name, int lives, Vector2 pos);

void boss_test_main_update(BossSprite* sprite);
void boss_test_main_render(BossSprite* sprite);

void boss_main_init(BossSprite sprite, Bosses current);
void boss_main_update(BossSprite* sprite, Bosses current);
void boss_main_render(BossSprite* sprite, Bosses current);

void boss_render_healthbar(BossSprite* sprite);

#endif // BOSS_H_
