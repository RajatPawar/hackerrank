#include <stdio.h>
#include <fcntl.h>

#define PERMS 0666

FILE* mfopen(char *fname, char *mode) {
    int fd = -1;
    FILE *fp;

    if(*mode != 'r' || *mode != 'w' || *mode != 'a')
        return NULL;
    
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++) // begin at the start of the iob array which handles the conccurent file access
        if(fp->flags & (_READ | _WRITE) == 0) // Not being written nor read 
            break;
    if(fp >= iob + OPEN_MAX) return NULL; // no free slot

    if(*mode == 'w') {
        // No matter what, just create a new file/overwrite old one
        fd = creat(fname, PERMS);
    }
    if(*mode == 'a') {
        if((fd = open(fname, O_WRONLY, PERMS)) == -1)
            fd = creat(fname, PERMS);
        
        // Go to end of file
        lseek(fd, 0, 2);
        // 0 means offset, 2 means origin (end of file)
    }
    else {
        if((fd = open(fname, O_RDONLY, PERMS)) == -1)
            return NULL;
    }
    fp->fd = fd;
    fp->base = NULL;
    fp->cnt = 0;
    fp->flags = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}
