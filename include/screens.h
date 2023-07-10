#ifndef SCREENS_H_
#define SCREENS_H_

#include <raylib.h>
#include <config.h>

typedef enum Screens {TITLE = 0, GAMEPLAY, ENDING} Screens;

void screens_render_title(void);
void screens_render_gameplay(void);
void screens_render_ending(void);

void screens_render(Screens* scr);

void screens_update_title(Screens* scr);
void screens_update_gameplay(Screens* scr);
void screens_update_ending(Screens* scr);

void screens_update(Screens* scr);

#endif // SCREENS_H_
