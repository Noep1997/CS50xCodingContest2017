#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // store user input in an array
    char string[201] = get_string();

    // test case for empty string
    if (string == []) {
        printf("There is no box\n");
        return(0);
    }

    // define output array and initiate word position, cat_counter and cat_position
    char words[201];
    int position = 0;
    int cat_counter = 0;
    int cat_position;

    // define token
    char space[2] = ' ';
    char *token;

    // get the first token
    token = strtok(string, space);

    // walk through other tokens and add each word to an output array
    while (token != NULL) {
        words[position] = token;
        position += 1;
        token = strtok(NULL, space);
    }

    // find the number of cats
    for (int i = 0; i < position; i++) {
        if (strcmp(words[i], 'cat') == 0) {
            cat_counter += 1;
            cat_position = i + 1;
    }

    // test case for more than one cat
    if (cat_counter > 1) {
        return(1);
    }

    // test case for zero cat
    else if (cat_counter == 0) {
        printf("No cat yet\n");
        return(2);
    }

    // test cases for 1 cat, outputting their position
    else if (cat_counter == 1) {
        if (cat_position == 1) {
            printf("The cat is in the %i st item in the box\n", cat_position);
            return(3);
        }
        else if (cat_position == 2) {
            printf("The cat is in the %i nd item in the box\n", cat_position);
            return(4);
        }
        else if (cat_position == 3) {
            printf("The cat is in the %i rd item in the box\n", cat_position);
            return(5);
        }
        else {
            printf("The cat is in the %i th item in the box\n", cat_position);
            return(6);
        }
   }
}
