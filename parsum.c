#include <stdio.h>
#include <stdlib.h>

#define K 1000000

// define variable Interpreter
typedef struct op
{
    int sum;
    void (*action)(struct op*, int add);
}Interpreter;

// initialize addition parameter
void add(Interpreter* op, const int add)
{
    op->sum += add;
}

// initialize substraction parameter
void min(Interpreter* op, const int add)
{
    op->sum -= add;
}

// add or substract the numbers
void number(const char* S, int* i, Interpreter* sum)
{
    // initialize variables
    char n[9] = ""; // max size + \0
    int j;

    // collect digits in a string and add or substrat when a non-digit character is reached
    for (j = 0; S[*i] != '\0' && S[*i] > 0x2F; (*i)++)
        n[j++] = S[*i];
    sum->action(sum, atoi(n));
    (*i)--;
}

// define whether to add or substract
void operator(const char* S, int* i, Interpreter* sum)
{
    char c = S[*i];
    if (c == '-')
        sum->action = min;
    else
        sum->action = add;
}

int parse(const char* S)
{
    void (*action[2])(const char*, int*, Interpreter*) = {number, operator};
    Interpreter sum;
    sum.sum = 0;
    sum.action = add;
    int cpt = 0;
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
        if (S[i] != ' ')
        {
            if (!cpt && S[i] == '-')
                cpt++;
            action[cpt&1](S, &i, &sum);
            cpt++;
        }
    }
    return sum.sum;
}

int main()
{
    // get user input
    char S[K];
    scanf("%[^\n]", S);

    // output result
    printf("%d", parse(S));

    // render success
    return 0;
}
