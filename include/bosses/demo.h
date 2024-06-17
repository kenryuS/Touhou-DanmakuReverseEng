#ifndef DEMO_H_
#define DEMO_H_

#include <raylib.h>
#include <boss.h>
#include <math.h>

#define BOSS_TEST_NAME "Test Boss"
#define BOSS_TEST_HEALTH 100.0f

void boss_test_main_update(BossSprite* sprite);
void boss_test_main_render(BossSprite* sprite);

void demo_shoot(BossSprite* sprite);


#endif // DEMO_H_
