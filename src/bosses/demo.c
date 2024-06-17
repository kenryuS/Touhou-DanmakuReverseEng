#include <bosses/demo.h>

void boss_test_main_update(BossSprite* sprite) {
    // update
    if (sprite->core.ticks == 0) {
        sprite->core.isActive = true;
        sprite->core.mode = RECT;
        sprite->core.aux_pos = (Vector2){0,0};
    }
    if (sprite->health <= 0) {
        sprite->lives--;
        if (sprite->lives > 0) sprite->health = 100.0f;
    }
    if (sprite->lives <= 0) {
        sprite->core.isActive = false;
    }

    sprite->health = sprite->health - 0.1;
    sprite->core.ticks++;
    sprite->core.time += GetFrameTime();
    demo_shoot(sprite);
}

void boss_test_main_render(BossSprite* sprite) {
    if (!sprite) return;
    if (sprite->core.isActive) {
        DrawCircleV(sprite->core.pos, 20, PURPLE);
    }
    //for (int i = 0; i < BOSS_MAX_TAMA_NUM; i++) {
    //    DrawCircleV((Vector2){sprite->tama[i].core.pos.x*cos(sprite->tama[i].core.pos.y) + sprite->tama[i].core.aux_pos.x, sprite->tama[i].core.pos.x*sin(sprite->tama[i].core.pos.y) + sprite->tama[i].core.aux_pos.y}, 5, BLUE);
    //}
}

void demo_shoot(BossSprite *sprite) {
    if (sprite->core.time < 1.0f) return;
    sprite->core.time = 0.0f;
    for (int i = 0; i < BOSS_MAX_TAMA_NUM; i++) {
        Tama* target = &(sprite->tama[i]);
        if (target->core.isActive == false) {
            target->core.isActive = true;
            target->core.aux_pos = sprite->core.pos;
            target->core.pos = (Vector2){0,PI/2};
        }
        if (target->core.pos.x > 1000 && target->core.isActive) {
            target->core.isActive = false;
            target->core.ticks = 0;
        }
        if (target->core.isActive) {
            sprite_translate(&(target->core), (Vector2){1024,0});
            target->core.ticks++;
            target->core.time += GetFrameTime();
        }
    }
}