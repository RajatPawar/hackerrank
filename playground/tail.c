#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    while(--argc > 0 && *(++argv)[0] == '-') {
        for(int i = 1; i < strlen(*argv); i++) (*argv)[i - 1] = (*argv)[i];
        (*argv)[strlen(*argv) - 1] = '\0';
        int lines = atoi(*argv);
    }
    return 0;
}
