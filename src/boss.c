#include <boss.h>

BossSprite boss_init(char* name, int lives, Vector2 pos) {
    BossSprite res = {};
    res.name = name;
    res.health = 100.0f;
    res.lives = lives;
    res.core = sprite_create(0, pos, (Vector2){0,0}, false, (Texture2D){}, 0);
    return res;
}

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

    sprite->health = sprite->health - 0.01;
    sprite->core.ticks++;
}

void boss_test_main_render(BossSprite* sprite) {
    if (!sprite) return;
    if (sprite->core.isActive) {
        DrawCircleV(sprite->core.pos, 20, PURPLE);
    }
}

void boss_main_init(BossSprite sprite, Bosses current) {
    switch (current) {
        case TEST:
            sprite = boss_init("Test", 1, (Vector2){SCREEN_WIDTH/3.0f, 50});
            printf("test inited\nHealth = %f", sprite.health);
            break;
    }
}

void boss_main_update(BossSprite* sprite, Bosses current) {
    switch (current) {
        case TEST:
            boss_test_main_update(sprite);
            break;
    }
}

void boss_main_render(BossSprite* sprite, Bosses current) {
    switch (current) {
        case TEST:
            boss_test_main_render(sprite);
            break;
    }
}

void boss_render_healthbar(BossSprite* sprite) {
    if (!sprite) return;
    if (sprite->core.isActive) {
        float width = sprite->health;
        DrawRectangle(10,10, width, 10, GRAY);
    }
}
