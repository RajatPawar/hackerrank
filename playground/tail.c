#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int numstrings = argc - 1, 
        linestoprint = 10;

    // numstrings counts how many strings are there, lines are default 10
        
    while(--argc > 0 && *(++argv)[0] == '-') {
        for(int i = 1; i < strlen(*argv); i++) (*argv)[i - 1] = (*argv)[i];
        (*argv)[strlen(*argv) - 1] = '\0';
        linestoprint = atoi(*argv);
        numstrings--; // counting this param, we have one less string 
    }
    
    while(numstrings && argc-- > 0) {
        if(numstrings-- - linestoprint <= 0) 
            printf("%s\n", *(argv++));
    }

    return 0;
}
