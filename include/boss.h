#ifndef BOSS_H_
#define BOSS_H_

#include <raylib.h>
#include <config.h>
#include <util.h>

typedef struct {
    float x;
    float y;
    bool isActive;
    unsigned int id;
    char* name;
    int health;
} Boss;

#endif // BOSS_H_
