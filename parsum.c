#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int total = 0;  
    char S[200];
    scanf("%[^\n]", S);

    int length = strlen(S);
    char *number;
    
    for (int c = 0; c < length; c++) {
       
        if (S[c] == '-') {
            
            while (S[c + 1] > 0x29 && S[c + 1] < 0x3A) {
                char number = number + S[c + 1];
                c++; 
            }
                        
            total -= atoi(number);
        }
        
        else if (S[c] == '+') {
            while (S[c + 1] > 0x29 && S[c + 1] < 0x3A) {
                
                char number = number + S[c + 1];
                c++;  
            }
            
            total += atoi(number);
        }    
    }
    
    printf("%i\n", total);
    return 0;
}