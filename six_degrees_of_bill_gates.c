#include <stdio.h>
#include <stdlib.h>

int seek(int** circles, const int N, int X, int Y)
{
    static int done[1000];
    int shortest = -1;
    int i;
    for(i = 0; i < N; i++)
    {
        if(circles[X][i] == 1)
        {
            if(i == Y)
                return 1;
            if(done[X] == 0)
            {
                done[X] = 1;
                int x = seek(circles, N, i, Y);
                if(shortest == -1 || x < shortest)
                    shortest = x;
            }
        }
    }
    return shortest < 0 ? shortest : shortest + 1;
}

int main()
{
    int N, X, Y, i, j;
    scanf("%d\n", &N);
    if(N < 2 || N > 100)
        printf("-1");

    int* circles[N];
    for(i = 0; i < N; i++)
    {
        circles[i] = malloc(sizeof(int)*N);
        for(j = 0; j < N; j++)
        {
            scanf("%d", &circles[i][j]);
            circles[i][j] = !!circles[i][j];
        }
        scanf("\n");
    }
    scanf("%d", &X);
    scanf("%d", &Y);
    printf("%d", seek(circles, N, X, Y));
    return 0;
}
