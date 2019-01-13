#include <stdio.h>
#include <fcntl.h>

int _flushbuff(FILE *fp) {
    if(fp->flag & (_ERR | _EOF | _WRITE) != _WRITE) fp->flag |= _ERR, return EOF; // Invalid file (errored out or not right mode)
    if(fp->base == NULL || fp->ptr == NULL) fp->flag |= _ERR, return EOF; // No buffer to flush
    if(fp->flag & _UNBUFF == 1) fp->flag |= _ERR, return EOF; //Unbuffered file, nothing to flush
    
    int bytes = (ptr - base);
    if(write(fp->fd, ptr->base, bytes) != bytes) 
        fp->flag |= _ERR, return EOF;
    
    fp->cnt -= bytes;
    fp->ptr = fp->base;

    return bytes;
}
