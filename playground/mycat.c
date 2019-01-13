#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 100
#define STDOUT   1

int main(int argc, char *argv[]) {
    
    int fd = -1;
    char buffer[BUFFSIZE];
    int readBytes = -1,
        wrBytes = -1;

    while(--argc > 0) {
        if((fd = open(*(++argv), O_RDONLY, 0)) != -1) {
            while((readBytes = read(fd, buffer, BUFFSIZE)) > 0) {
                if((wrBytes = write(STDOUT, buffer, readBytes)) != readBytes) { 
                    printf("\nERROR: Can't write to stdout\n");
                    break;
                }
            }
        }
    }
    return 0;
}
