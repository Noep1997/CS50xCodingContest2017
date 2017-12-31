#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 200*45

void capitalize(char* c)
{
    if(*c > 0x60 && *c < 0x7B)
        *c -= 0x20;
}
int checkWord(char* w)
{
    static const char words[4][5] = {"the","and","of","but"};
    int i;
    for(i = 0; i < 4 && strcmp(w, words[i]); i ++);
    return i == 4;
}
void run(char* S)
{
    char tmp[45];
    int i, j;
    capitalize(&S[0]);
    for(i = 0; i < N && S[i] != '\0'; i++)
    {
        for(j = i; i < N && S[i] != '\0'&&S[i] != ' '; i++)
            tmp[i-j] = S[i];
        tmp[i - j] = '\0';
        if(checkWord(tmp))
            S[j] = toupper(S[j]);
    }
    capitalize(&S[j]);
}
int main()
{
    char S[N];
    scanf("%[^\n]", S);
    if(S[0] != '\0')
        run(S);
    printf("%s",S);
    return 0;
}
