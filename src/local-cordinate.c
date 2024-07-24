#include <local-cordinate.h>

void toLocalCord(Vector2* pixel_cord, Local_Cordinate_System *cord_sys, Local_Cordinate *dest) {
    dest->cord_sys = cord_sys;
    if (cord_sys->mode == RECT) {
        double l_x = (pixel_cord->x - cord_sys->origin.x) / cord_sys->scaling.x;
        double l_y = (pixel_cord->y - cord_sys->origin.y) / cord_sys->scaling.y;
        dest->cord = (Vector2){l_x, l_y};
    } else if (cord_sys->mode == POLAR) {
        double angle = atan2((pixel_cord->y - cord_sys->origin.y) / cord_sys->scaling.y, (pixel_cord->x - cord_sys->origin.x) / cord_sys->scaling.x);
        double radius = sqrt(pow((pixel_cord->x - cord_sys->origin.x) / cord_sys->scaling.x, 2) + pow((pixel_cord->y - cord_sys->origin.y) / cord_sys->scaling.y, 2));
        dest->cord = (Vector2){radius, angle};
    }
    return;
}

void toPixelCord(Local_Cordinate *local_cord, Vector2 *dest) {
    if (local_cord->cord_sys->mode == RECT) {
        double p_x = (local_cord->cord.x * local_cord->cord_sys->scaling.x) + local_cord->cord_sys->origin.x;
        double p_y = (local_cord->cord.y * local_cord->cord_sys->scaling.y) + local_cord->cord_sys->origin.y;
        *dest = (Vector2){p_x, p_y};
    } else if (local_cord->cord_sys->mode == POLAR) {
        double p_x = (local_cord->cord.x * local_cord->cord_sys->scaling.x) * cosf(local_cord->cord.y) + local_cord->cord_sys->origin.x;
        double p_y = (local_cord->cord.x * local_cord->cord_sys->scaling.y) * sinf(local_cord->cord.y) + local_cord->cord_sys->origin.y;
        *dest = (Vector2){p_x, p_y};
    }
    return;
}

Local_Cordinate toLocalCordV(Vector2 *pixel_cord, Local_Cordinate_System *cord_sys) {
    Local_Cordinate res = { 0 };
    toLocalCord(pixel_cord, cord_sys, &res);
    return res;
}

Vector2 toPixelCordV(Local_Cordinate *local_cord) {
    Vector2 res = { 0 };
    toPixelCord(local_cord, &res);
    return res;
}
