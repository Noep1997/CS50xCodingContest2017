#include <stdio.h>
#include <stdlib.h>

typedef struct f
{
    int s;
    int h;
    struct f** others;
}Food;


int seekBest(Food* f, int i, int N, int totalH, int totalS, const int L, int* max)
{
    totalH+=f->h;
    totalS+=f->s;

    for(; i < N; i++)
        seekBest(f->others[i], i+1, N, totalH, totalS, L, max);

    if(L < totalS)
        totalH -= (totalS - L) * 20;
    else if(L > totalS)
        totalH -= (L - totalS) * 10;

    if(totalH > *max)
        *max = totalH;
    return 0;
}

int main()
{
    int L, N, i, j, s, h, max = 0;
    scanf("%d", &L);
    scanf("%d", &N);
    Food food[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d, %d", &s, &h);
        food[i].s = s;
        food[i].h = h;
        food[i].others = calloc(sizeof(Food*), N);
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            food[i].others[j] = &food[j];
    }
    for(i = 0; i < N; i++)
        seekBest(&(food[i]), i+1, N, 0, 0, L, &max);

    printf("%d", max);
    for(i = 0; i < N; i++)
        free(food[i].others);
    return 0;
}
