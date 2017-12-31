#include <stdio.h>
#include <stdlib.h>

typedef struct aabb
{
    float x;
    float y;
    float w;
    float h;
}AABB;

void inputAABB(AABB* a)
{
    scanf("%f %f %f %f", &(a->x), &(a->y), &(a->w), &(a->h));
}
float getOverLapping(float x1, float w1, float x2, float w2)
{
    float y;
    if(x1 < x2)
    {
        float z = x2 - x1;
        y = w1 - z;
        if(y < 0)
            return 0;
        if(w2 + x2 < x1 + w1)
            y = w2;
    }
    else
    {
        float z = x1 - x2;
        y = w2 - z;
        if(y < 0)
            return 0;
        if(w2 + x2 > x1 + w1)
            y = w1;
    }
    return y;
}

int main()
{
    AABB a1;
    AABB a2;
    inputAABB(&a1);
    inputAABB(&a2);
    float w = getOverLapping(a1.x, a1.w, a2.x, a2.w);
    float h = getOverLapping(a1.y, a1.h, a2.y, a2.h);
    printf("%.2f", w*h);
    return 0;
}
