#ifndef MAIN_H_
#define MAIN_H_

#include "config.h"
#include <raylib.h>
#include "player.h"
#include "game.h"
#include "boss.h"
#include <stdlib.h>
#include "screens.h"
#include "screens/title.h"
#include "screens/gameSetup.h"
#include "screens/gamePlay.h"
#include "screens/gameEnd.h"

void update(Game *game);
void draw(Game *game);

int main(int argc, char** argv);

#endif // MAIN_H_
