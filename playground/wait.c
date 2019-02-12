#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define STDOUT 1

int main() {
    pid_t child_process_id = fork();
    if(child_process_id) {
        // Executed by parent
        write(STDOUT, "\nParent: Entering!", 18);
        wait(NULL);
        write(STDOUT, "\nParent: Exiting", 16);
    }
    else {
        // Executed by child
        write(STDOUT, "\nChild: Hello", 13);
    }
    write(STDOUT, "\nExit: Bye!\n", 12);
    return 0;
}
