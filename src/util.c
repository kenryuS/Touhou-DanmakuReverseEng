#include <math.h>
#include <util.h>

void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char c;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

Vector2 rectToPol(Vector2 rectFrom, Vector2 center) {
    Vector2 out = {0.0f, 0.0f};
    double r2 = ((rectFrom.x - center.x) * (rectFrom.x - center.x)) + ((rectFrom.y - center.y) * (rectFrom.y - center.y));
    out.x = (float)sqrt(r2);// radius
    out.y = atanf((rectFrom.y - center.y)/(rectFrom.x - center.x)); // theta
    return out;
}

Vector2 polToRect(Vector2 polForm, Vector2 center) {
    Vector2 out = {0.0f, 0.0f};
    out.x = polForm.x * cosf(polForm.y) + center.x;
    out.y = polForm.x * sinf(polForm.y) + center.y;
    return out;
}
