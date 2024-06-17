#include <boss.h>

#include <bosses/demo.h>

BossSprite boss_init(char* name, int lives, Vector2 pos) {
    BossSprite res = {};
    res.name = name;
    res.health = 100.0f;
    res.lives = lives;
    res.core = sprite_create(RECT, pos, (Vector2){0,0}, false, NULL, HB_CIRCLE);
    for (int i = 0; i < BOSS_MAX_TAMA_NUM; i++) {
        tama_init(&(res.tama[i]), (Vector2){0,0}, NORMAL, NULL, false, HB_CIRCLE);
    }
    return res;
}

void boss_main_init(BossSprite* sprite, Bosses current) {
    switch (current) {
        case DEMO:
            *sprite = boss_init(BOSS_TEST_NAME, 3, (Vector2){SCREEN_WIDTH/3.0f, 50});
            sprite->core.isActive = true;
            break;
    }
}

void boss_main_update(BossSprite* sprite, Bosses current) {
    switch (current) {
        case DEMO:
            boss_test_main_update(sprite);
            break;
    }
}

void boss_main_render(BossSprite* sprite, Bosses current) {
    switch (current) {
        case DEMO:
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
