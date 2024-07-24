#ifndef LOCAL_CORD_H_
#define LOCAL_CORD_H_

#include <raylib.h>
#include "util.h"

typedef enum {
    RECT,
    POLAR
} Cordinate_Mode;

typedef struct {
    Vector2 origin;
    Vector2 scaling;
    Cordinate_Mode mode;
} Local_Cordinate_System;

typedef struct {
    Local_Cordinate_System* cord_sys;
    Vector2 cord;
} Local_Cordinate;

void initLocalCordSys(Vector2 *orgin, Vector2 *scaling, Cordinate_Mode mode, Local_Cordinate_System *dest);
void toLocalCord(Vector2* pixel_cord, Local_Cordinate_System* cord_sys, Local_Cordinate* dest);
void toPixelCord(Local_Cordinate* local_cord, Vector2* dest);

Local_Cordinate toLocalCordLC(Vector2* pixel_cord, Local_Cordinate_System* cord_sys);
Vector2 toPixelCordV(Local_Cordinate* local_cord);

#endif // !LOCAL_CORD_H_
