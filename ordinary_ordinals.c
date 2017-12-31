#include <cs50.h>
#include <string.h>
#include <stdio.h>

#define MAX_ENGLISH_WORD_LENGTH 45
static const int LENGTH = 20000 * (MAX_ENGLISH_WORD_LENGTH + 1);

// search the input string for the word cat
int search(char* s)
{
    // define the possible endings for the position and word_count
    static const char ending[4][3] = {"th","st","nd","rd"};
    int word_count = 1;

    for (int i = 0; i < LENGTH - 4 && s[i] != '\0'; i++)
    {
        // increment word_count when space reached
        if (s[i] == ' ')
            word_count++;

        else if ((!i || s[i - 1] == ' ') && s[i] == 'c' && s[i + 1] == 'a' && s[i + 2] == 't' && (s[i + 3] == ' ' || s[i + 3] == '\0'))
        {
            // succesful, cat found
            printf("The cat is the %d%s item in the box", word_count, ending[(((word_count % 10) > 3 || (word_count % 100 < 14 && word_count % 100 > 10)) ? 0 : (word_count % 10))]);
            return 1;
        }
    }

    // unsucessful, no cat found
    return 0;
}

int main()
{
    // get string from user input
   // string input = get_string() + '\0';
    char s[LENGTH]; //strcpy(s, input);
    scanf("%[^\n]", s);
    // test case for empty string
    if (s[0] == '\0')
        printf("There is no box\n");

    // test case for no cat found
    else if (!search(s))
        printf("No cat yet\n");

    // success
    return 0;
}    
