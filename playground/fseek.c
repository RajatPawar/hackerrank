#include <stdio.h>
#include <fcntl.h>

#define START 0
#define END   2
#define CURR  1

int fseek(FILE *fp, int offset, int origin) {
    
    int res = -1;
    // Check if the file pointer actually exists 
    if(!fp) return NULL;

    // Check if the descriptor is actually valid 
    if(fp->fd < 0) return NULL;

    // Check the flags to see if the file is in write mode
    // If yes, then just flush the file 
    
    if(fd->flags & _READ)
    {
        // Take the pointer to the given place and update the 
        // struct information accordingly
        
        if(offset > fd->cnt) return EOF;
        fd->cnt -= offset;
        
        if(origin == START) fd->ptr = fd->base;
        else if(origin == END) 
        {
            fd->ptr = fd->base + BUFSIZ - 1;
            fd->cnt = 0;
        }
        else
            fd->ptr += offset;
    
        // Do the actual seek
        res = lseek(fp->fd, offset, origin);
    }
    // Not sure about behavior in _WRITE mode?
    return res;
    
}
