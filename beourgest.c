#include <string.h>
#include <stdio.h>


int is_available() {
    
    int consecutive = 0;
    
    for (int i = 0; i < floors; i++) {
        
        int length = strlen(floors_layout[i]);
        
        for (int c = 0; c < length; c++) {
            
            if (floors_layout[i][c] == 0) {
                consecutive += 1;
                
                if (consecutive == consecutive_rooms) {
                return 1;
                }
            }
            
            else
                consecutive = 0;
        }       
    }
    
    return 0;
    
}

int main(void)
{
    char input = scanf("[^\n]");
    const char space[2] = " ";
    
    int floors = atoi(strtok(input, space));
    
    int rooms = atoi(strtok(NULL, space));
    
    char floors_layout[floors]; 
    
    for (int i = 0; i < floors; i++) {
        floors_layout[i] = get_string(); 
    }
    
    int consecutive_rooms = get_int();

    if (is_available)
        printf("1\n");
    
    else
        printf("0\n");
    
    return 0;
    
}