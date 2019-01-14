#include <stdio.h>
#include <fcntl.h>

int mfclose(FILE *fp) {
    if(fp->flags & (_READ | _WRITE) == (_READ | _WRITE)) return EOF; // This is an empty file handle
    if(fp->fd < 0 || fp == NULL) return EOF; // Invalid file descriptor
    if(fp->base && fp->ptr) {
        free(fp->base);
        fp->ptr = fp->base = NULL;
    }
    fp->flags = fp->cnt = fp->fd = 0;
    return 1;
}
