#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define SERV_BACKLOG    (5)

int readbytes(int, unsigned int, char*);
void handle(int);

int main(int argc, char* argv[]) {
    unsigned short port;
    if(argc != 2) {
        perror("\nUsage: dir_server <listen_port>\n");
        exit(1);
    }

    port = htons(atoi(argv[1]));
    
    int server_socket;

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("\nSOCKET: Couldn't create");
        exit(1);
    }

    struct sockaddr_in server_struct, client_struct;
    int client_struct_size;

    server_struct.sin_port          = port;
    server_struct.sin_family        = AF_INET;
    inet_aton("localhost", &server_struct.sin_addr.s_addr);

    if((bind(server_socket, (struct sockaddr*) &server_struct, sizeof(server_struct))) == -1) {
        perror("\nSOCKET: Couldn't bind");
        exit(1);
    }

    if(listen(server_socket, SERV_BACKLOG) == -1) {
        perror("SOCKET: Couldn't listen");
        exit(1);
    }

    while(1) {
        int accepted_conn_socket;
        if((accepted_conn_socket = accept(server_socket, (struct sockaddr*) &client_struct, &client_struct_size)) == -1) {
            perror("SOCKET: Couldn't accept");
        }
        int process = fork();
        if(process) {
            // Parent process
            //close(accepted_conn_socket);
        }
        else {
            // Child process - handle client connection
            //close(server_socket);
            handle(accepted_conn_socket); 
            exit(0);
        }
    }
    return 0;
}

char* get_ftype(int n) {
    if(n == DT_DIR) return "Directory";
    return "File";
}

int readbytes(int socket, unsigned int len, char* buffer) {
    int lastread = 0, bytesread = 0, result;
    while(bytesread < len) {
        result = read(socket, buffer + bytesread, len - bytesread);
        if(result == lastread && lastread < 1) 
            return 0;
        bytesread += result;
        lastread = result;
    }
    return bytesread;
}

void handle(int client_socket_handle) {
    char *buffer, 
         *prompt = "\nChoose: \n1. Know my dir structure\n2. Send your dir struct to be printed out here\nEnter choice: ";
    
    buffer = (char*) malloc(sizeof(char) * 256);
    
    if(write(client_socket_handle, prompt, strlen(prompt) + 1) < 0) {
        perror("\nWRITE: Error");
        exit(1);
    }
    
    int choice;

    if((read(client_socket_handle, &choice, sizeof(choice))) < 0) {
        perror("\nREAD: Error");
        exit(1);
    }
    
    choice = ntohl(choice);
    printf("\nRead: %d", choice);

    switch(choice) {
        case 1: {
            memset(buffer, 0, 255);
            // Send dir struct
            DIR *dir_ptr = opendir(".");
            struct dirent *dir_entry_ptr;
            if(!dir_ptr) {
                perror("\nDIRERROR: Unable to open dir");
                exit(1);
            }

            int counter = 0, written_bytes = 0;
            while((dir_entry_ptr = readdir(dir_ptr)) != NULL) {
                sprintf(buffer, "\n%d. %s (%s)", ++counter, dir_entry_ptr->d_name, get_ftype(dir_entry_ptr->d_type));
                if(write(client_socket_handle, buffer, sizeof(buffer)) < 0) {
                    perror("\nWRITE: Error");
                    exit(1);
                }
            }
            break;
        }
        case 2: {
            // Receive dir struct and print
            memset(buffer, 0, 255);
            while(readbytes(client_socket_handle, 255, buffer)) {
                printf("%s", buffer);
            }
            break;
        }
        default: {
            break;       
        }
    }
    
    printf("\n\nThat's it, folks!\n\n");
    close(client_socket_handle);
}
