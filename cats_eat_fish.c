#include <string.h>
#include <stdio.h>

int main(void)
{
    int fishes, days, meal, nofish;

    scanf("%d", &fishes);
    scanf("%d", &days);

    for (int i = 0; i < days; i++) {
        scanf("%d", &meal);
        fishes -= meal;

        if (fishes <= 0 && nofish == 0) {
            nofish = i;
        }
    }

    if (fishes > 0)
        printf("Happy Cat!");
    else
        printf("%d", nofish);

    return 0;
}
