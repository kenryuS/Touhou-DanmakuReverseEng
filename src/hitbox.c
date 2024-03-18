#include <hitbox.h>
#include <raylib.h>

bool isCollided(Hitbox h1, Hitbox h2) {
    bool res = false;
    switch (h1.type) {
        case HB_CIRCLE:
            switch (h2.type) {
                case HB_LINE:
                    res = CheckCollisionLineCircle(h2.core.line.start, h2.core.line.end, h1.core.circle.center, h1.core.circle.radius);
                    break;
                case HB_RECT:
                    res = CheckCollisionCircleRec(h1.core.circle.center, h1.core.circle.radius, (Rectangle){h2.core.rect.pos.x, h2.core.rect.pos.y, h2.core.rect.size.x, h2.core.rect.size.y});
                    break;
                case HB_CIRCLE:
                    res = CheckCollisionCircles(h1.core.circle.center, h1.core.circle.radius, h2.core.circle.center, h1.core.circle.radius);
                    break;
            }
            break;
        case HB_LINE:
            switch (h2.type) {
                case HB_LINE:
                    res = CheckCollisionLines(h1.core.line.start, h1.core.line.end, h2.core.line.start, h2.core.line.end, &(Vector2){});
                    break;
                case HB_RECT:
                    res = CheckCollisionLineRect(h1.core.line.start, h1.core.line.end, (Rectangle){h2.core.rect.pos.x, h2.core.rect.pos.y, h2.core.rect.size.x, h2.core.rect.size.y});
                    break;
                case HB_CIRCLE:
                    res = CheckCollisionLineCircle(h1.core.line.start, h1.core.line.end, h2.core.circle.center, h2.core.circle.radius);
                    break;
            }
            break;
        case HB_RECT:
            switch (h2.type) {
                case HB_LINE:
                    res = CheckCollisionLineRect(h2.core.line.start, h2.core.line.end, (Rectangle){h1.core.rect.pos.x, h1.core.rect.pos.y, h1.core.rect.size.x, h1.core.rect.size.y});
                    break;
                case HB_RECT:
                    res = CheckCollisionRecs((Rectangle){h1.core.rect.pos.x, h1.core.rect.pos.y, h1.core.rect.size.x, h1.core.rect.size.y}, (Rectangle){h2.core.rect.pos.x, h2.core.rect.pos.y, h2.core.rect.size.x, h2.core.rect.size.y});
                    break;
                case HB_CIRCLE:
                    res = CheckCollisionCircleRec(h2.core.circle.center, h2.core.circle.radius, (Rectangle){h1.core.rect.pos.x, h1.core.rect.pos.y, h1.core.rect.size.x, h1.core.rect.size.y});
                    break;
            }
            break;
    }
    return res;
}

void hitbox_render(Hitbox target) {
    switch (target.type) {
        case HB_CIRCLE: {
            DrawCircleV(target.core.circle.center, target.core.circle.radius, BLACK);
            break;
        }
        case HB_LINE: {
            DrawLineV(target.core.line.start, target.core.line.end, BLANK);
            break;
        }
        case HB_RECT: {
            DrawRectangleV(target.core.rect.pos, target.core.rect.size, BLANK);
            break;
        }
    }
    return;
}


bool CheckCollisionLineCircle(Vector2 startPos, Vector2 endPos, Vector2 center, float radius) {
    // check the intersection # of y = m*x+n and (x-a)^2 + (y-b)^2 = r^2
    bool collision = false;
    float m = (endPos.y - startPos.y)/(endPos.x - startPos.x);
    float n = startPos.y - m*startPos.x;
    float A = (m*m + 1);
    float B = (2*(m*(n-center.y) - center.x));
    float C = (center.x*center.x) + (n*n) - (2*n*center.y) + (center.y*center.y) - (radius*radius);
    float D = (B*B) - 4*A*C;
    if (D > 0 || D == 0) {
        // integral(sqrt(1+m*m), endPos.x, t1) = sqrt(1+m*m)(t1-endPos.x) = r
        // integral(sqrt(1+m*m), t2, startPos.x) = sqrt(1+m*m)(startPos.x-t2) = r
        // integral(sqrt(1+m*m), t3, endPos.x) = sqrt(1+m*m)(endPos.x-t3) = r
        // integral(sqrt(1+m*m), startPos.x, t4) = sqrt(1+m*m)(t4-startPos.x) = r
        // t1 = r/sqrt(1+m*m) + endPos.x
        // t2 = -r/sqrt(1+m*m) + startPos.x
        // t3 = -r/sqrt(1+m*m) + endPos.x
        // t4 = r/sqrt(1+m*m) + startPos.x
        // t3 <= x <= t1 OR t2 <= x <= t4
        float LineInteg = sqrtf(1.0f + m*m);
        float t1 = radius/LineInteg + endPos.x;
        float t2 = -radius/LineInteg + startPos.x;
        float t3 = -radius/LineInteg + endPos.x;
        float t4 = radius/LineInteg + startPos.x;

        if ((t3 <= center.x && center.x <= endPos.x) || (startPos.x <= center.x && center.x <= t4)) {
            collision = CheckCollisionCircles(center, radius, startPos, radius) || CheckCollisionCircles(center, radius, endPos, radius);
        } else if (endPos.x <= center.x && center.x <= t1 || t2 <= center.x && center.x <= startPos.x) {
            collision = CheckCollisionPointCircle(center, startPos, radius) || CheckCollisionPointCircle(center, endPos, radius);
        } else if (startPos.x <= center.x && center.x <= endPos.x) {
            collision = true;
        } else {
            collision = false;
        }
    }
    return collision;
}

bool CheckCollisionLineRect(Vector2 startPos, Vector2 endPos, Rectangle rect) {
    bool collision = false;
    if (CheckCollisionLines(startPos, endPos, (Vector2){rect.x, rect.y}, (Vector2){rect.x, rect.y+rect.height}, &(Vector2){}) ||
        CheckCollisionLines(startPos, endPos, (Vector2){rect.x, rect.y}, (Vector2){rect.x+rect.width, rect.y}, &(Vector2){})  ||
        CheckCollisionLines(startPos, endPos, (Vector2){rect.x, rect.y+rect.height}, (Vector2){rect.x+rect.width, rect.y+rect.height}, &(Vector2){}) ||
        CheckCollisionLines(startPos, endPos, (Vector2){rect.x+rect.width, rect.y}, (Vector2){rect.x+rect.width, rect.y+rect.height}, &(Vector2){})
    ) collision = true;
    return collision;
}
