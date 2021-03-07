#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define INPUT_BUFFER_SIZE 1024
#define REPLY_BUFFER_SIZE 10 * 1024 * 1024
char input[INPUT_BUFFER_SIZE];
char reply[REPLY_BUFFER_SIZE];

void process_error(char *message)
{
    if (message == NULL){
        perror("Error");
    } else {
        fputs(message, stderr);
    }
}

int close_socket(int socket)
{
    int result = -1;

    if (-1 == shutdown(socket, SHUT_RDWR)) {
        process_error(NULL);
    } else {
        if (-1 == close(socket)){
            process_error(NULL);
        } else {
            result = 1;
        }
    }

    return result;
}

int main(int argc, char **argv)
{
    int client_socket;

    struct sockaddr_in server_address;

    struct hostent *host_ip_addresses;
    struct in_addr *host_ip_address;

    if (argc < 3){
        process_error("Usage: nc <host> <port>.");
        exit(EXIT_FAILURE);
    }

    if (!(host_ip_addresses = gethostbyname(argv[1]))){
        herror(NULL);
        exit(EXIT_FAILURE);
    }

    host_ip_address = (struct in_addr *) *(host_ip_addresses->h_addr_list);
    printf("Server IP: %s\n", inet_ntoa(*host_ip_address));
    
    client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); 

    if (client_socket == -1){ 
        process_error(NULL); 
        exit(EXIT_FAILURE); 
    }

    memset(&server_address, 0, sizeof(server_address));         //set num of serveraddress bytes to 0
    server_address.sin_family = AF_INET;
    server_address.sin_port   = htons(atoi(argv[2]));
    server_address.sin_addr   = *host_ip_address;

    if (-1 == connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address))){
        process_error(NULL); 
        close_socket(client_socket); 
        exit(EXIT_FAILURE); 
    }
    
    size_t bytes_read;
    
    while (0 <= (bytes_read = read(0, input, INPUT_BUFFER_SIZE - 4)))
    {
        input[bytes_read - 1] = '\r';
        input[bytes_read]     = '\n';
        input[bytes_read + 1] = '\r';
        input[bytes_read + 2] = '\n';
        input[bytes_read + 3] = '\0';
        
        if (-1 == send(client_socket, input, bytes_read + 4, 0)){
            process_error(NULL); 
            close_socket(client_socket); 
            exit(EXIT_FAILURE); 
        }

        memset(&reply, 0, REPLY_BUFFER_SIZE);
    
        if (-1 == recv(client_socket, reply, REPLY_BUFFER_SIZE, MSG_WAITALL)){
            process_error(NULL); 
            close_socket(client_socket); 
            exit(EXIT_FAILURE); 
        }
      
        printf("\nReply: %s\n", reply);
    }

    if(-1 == close_socket(client_socket)){
            exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
