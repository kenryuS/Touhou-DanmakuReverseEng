#ifndef UTILS_H_
#define UTILS_H_

#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void itoa(int n, char s[]);

void reverse(char s[]);

Vector2 rectToPol(Vector2 rectForm, Vector2 center);

Vector2 polToRect(Vector2 polForm, Vector2 center);
#endif // UTILS_H_
