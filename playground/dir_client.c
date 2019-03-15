#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <dirent.h>

char* get_ftype(int n) {
    if(n == DT_DIR) return "Directory";
    return "File";
}

int readbytes(int socket, unsigned int x, char *buffer) {
    int bytesread = 0, lastread = 0;
    int result;
    while(bytesread < x) {
        result = read(socket, buffer + bytesread, x - bytesread);
        
        if(lastread == result && lastread < 1) 
            return 0;
        
        bytesread += result;
        lastread = result;
    }
    return bytesread;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        perror("\nUsage: dir_client <IP> <port>");
        exit(1);
    }
    
    struct sockaddr_in server_struct;
    struct hostent *server_information;

    server_information = gethostbyname(argv[1]);
    if(!server_information) {
        perror("\nERROR: Couldn't retrieve server information");
        exit(1);
    }

    int socket_conn;
    unsigned short port = htons(atoi(argv[2]));

    if((socket_conn = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("\nSOCKET: Couldn't create");
        exit(1);
    }
    
    inet_aton(server_information->h_addr, &server_struct.sin_addr.s_addr);
    server_struct.sin_port   = port;
    server_struct.sin_family = AF_INET;

    if(connect(socket_conn, (struct sockaddr *) &server_struct, sizeof(server_struct)) == -1) {
        perror("\nSOCKET: Couldn't connect");
        exit(1);
    }
    
    char buffer[256];
    
    if(read(socket_conn, &buffer, sizeof(buffer)) < 0) {
        perror("\nREAD: Error");
        exit(1);
    }

    printf("\n%s", buffer);
    memset(buffer, 0, sizeof(buffer));

    int choice;
    
    scanf("%d", &choice);
    choice = htonl(choice);
    
    if(write(socket_conn, &choice, sizeof(choice)) < 0) {
        perror("ERROR: Couldn't send choice");
        exit(1);
    }
    
    choice = ntohl(choice);

    switch(choice) {
        case 1: {
            // Get server dir info and print here
            while(readbytes(socket_conn, 255, buffer))
                printf("%s", buffer);
            break;
        }
        case 2: {
           // Send dir info and get it printed there
            DIR *dir_ptr = opendir(".");
            struct dirent *dir_entry_ptr;
            int counter = 0;

            if(!dir_ptr) {
                perror("\nCouldn't open directory");
                exit(1);
            }

            while((dir_entry_ptr = readdir(dir_ptr)) != NULL) {
                sprintf(buffer, "\n%d. %s (%s)", ++counter, dir_entry_ptr->d_name, get_ftype(dir_entry_ptr->d_type));
                if((write(socket_conn, buffer, sizeof(buffer))) < 0) {
                    perror("\nWRITE: Error");
                    exit(1);
                }
            }
            break;
        }
        default: {
            printf("\nDefault");
            break;
        }
    }
    
    printf("\n\nThat's it folks!\n");
    close(socket_conn);
    return 0;
}
