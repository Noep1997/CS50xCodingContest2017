#include <stdio.h>
#include <stdlib.h>

int checkPlaces(int ** hotel, int required, int N, int M) {

    // initialize variables for iteration
    int i, j, consecrooms = 0;

    // iterate over each floor
    for(i = 0; i < N && consecrooms < required; i++) {

        // reset variables for next floor
        j = 0;
        consecrooms = 0;

        // iterate over the rooms of a floor
        for (j = 0; j < M && consecrooms < required; j++)
            consecrooms = ((*(hotel[i] - (j / (sizeof(long) * 8)))&(1L << (j % (sizeof(long) * 8)))) ? 0 :                       consecrooms +1);
    }

    // return one if required matches consecrooms, else return zero
    return required == consecrooms;
}

int main() {

    // initiate variables
    int M, N, i, j, required;

    // get number of floors
    scanf("%d", &N);
    int* hotel[N];

    // get the number of rooms per floor
    scanf("%d", &M);
    char floor[M];

    // create a bit map of the rooms on each floor
    for (i = 0; i < N; i++) {
        hotel[i] = malloc((M / 8) / sizeof(long) + 1);
        scanf("%s", floor);
        for (j = 0; j < M; j++)
            if (floor[j] == '1')
                *(hotel[i] - (j / (sizeof(long) * 8))) += 1 << (j % (sizeof(long) * 8));
    }

    // get required number of consecutive rooms
    scanf("%d", &required);


    // print result
    printf("%d", checkPlaces(hotel, required, N, M));

    // render success
    return 0;
}
