#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "../include/sockets.h"

#define PORT 8080
#define BACKLOG 5

void start_socket_server(const char *interface_ip) {
    int server_fd; 
    struct sockaddr_in server_addr; 

    // create tcp socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_fd == -1) {
        perror("socket"); 
        exit(EXIT_FAILURE);
    }

    // configure server address structure
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr(interface_ip);
    server_addr.sin_port = htons(PORT); 

    // binding socket to selected IP 
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind"); 
        close(server_fd); 
        exit(EXIT_FAILURE); 
    }

    // listening for incoming connections
    if (listen(server_fd, BACKLOG) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Listening on %s:%d...\n", interface_ip, PORT); 

    // accept and handle connections
    while (1) {
        struct sockaddr_in client_addr; 
        socklen_t client_len = sizeof(client_addr); 
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len); 

        if (client_fd < 0) {
            perror("accept"); 
            continue; 
        }

        char client_ip[INET_ADDRSTRLEN]; 
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip)); 
        printf("New connection from %s\n", client_ip);

        close(client_fd);
    } 

    close(server_fd);
}