#include <string.h>
#include <stdio.h>

#define N 100000

// find longest word
int longestWord(const char* S)
{
    // initialize variables
    int i, j, longest = 0;

    // loop through the string to find a word
    for (i = 0; S[i] != '\0'; i++) {
        for (j = i; S[j] != '\0' && S[j] != ' '; j++);


        // update longest if new word found is longer
        if (longest < j - i)
            longest = j - i;
    }

    // render success
    return longest;
}

// print top line of the frame
void printSpecialLine(const int l)
{
    for (int i = 0; i < l; i++)
        printf("#");
}

// print a line of the frame
void printLine(const int l, const char* S)
{
    // initialize variable and print left part of the frame
    int i;
    printf("# ");

    // loop through the word and print it
    for (i = 0; S[i] != '\0'; i++)
        printf("%c", S[i]);

    // print required spaces to equal longest word
    for (; i < l; i++)
        printf(" ");

    // print right part of the frame
    printf(" #\n");
}





void printing(const char* S, const int l)
{
    // initialize variables
    int i, j;
    char n[45] = "";

    // print first line
    printSpecialLine(l + 4);
    printf("\n");

    // print the middle lines
    for (i = 0, j = 0; S[i] != '\0'; i++) {

        // print word until space reached
        if (S[i] != ' ')
            n[j++] = S[i];

        // print word until end of string reached
        else {
            n[j++] = '\0';
            j = 0;
            printLine(l, n);
        }
    }

    // print last to final line and final line
    printLine(l, n);
    printSpecialLine(l + 4);
}

int main(void)
{
    // get user input
    char S[N];
    scanf("%[^\n]", S);

    // get longest word
    int l = longestWord(S);

    // render success
    printing(S, l);
    return 0;
}
