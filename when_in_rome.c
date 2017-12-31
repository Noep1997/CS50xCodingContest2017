#include <string.h>
#include <stdio.h>

#define N 200

// define roman numbers decimal values
int number(char c) {
    return(c == 'I' ? 1 : (c == 'V' ? 5 : (c == 'X' ? 10 : (c == 'L' ? 50 : (c == 'C' ? 100 : (c == 'D' ? 500 : c ==           'M' ? 1000 : 0))))));
}

// transform the roman number to decimal
int numerize(const char* S) {
    // initialize variables
    int i, sum = 0, tmp = 0;

    // sum numbers according to roman numbers rules
    for (i = 0; S[i] != '\0'; i++) {

        tmp = number(S[i]);
        sum += tmp >= number(S[i + 1]) ? tmp : -tmp;
    }

    // render success
    return sum;
}

int main(void) {
    // get user input
    char S[200];
    scanf("%[^\n]", S);

    // render success
    printf("%d\n", numerize(S));
    return 0;
}
