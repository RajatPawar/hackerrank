#include <stdio.h>

int is_alt(char *s) {

        char *itr = s + 1;
        while(*itr) {
            if(itr != s && *(itr + 1) != '\0') {
                    if(*(itr - 1) == *(itr + 1) && *itr != *(itr - 1)) 
                    {
                        itr++;
                        continue;
                    }            
                    else return 0;
                                                
            }
            else itr++;    
        }
            return 1;

}

int main() {
    printf("\nalt(ebababae): %d", is_alt("ebababae"));
    printf("\nalt(baebaba): %d", is_alt("baebaba"));
    return 0;
}
