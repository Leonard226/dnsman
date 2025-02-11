#include <stdio.h>
#include "../include/interfaces.h"
#include "../include/sockets.h"

int main() {
    printf("Listing active network interfaces:\n");
    list_active_interfaces(); 
    
    const char *interface_ip = "192.168.178.25"; 

    printf("Starting socket server on %s...\n", interface_ip);
    start_socket_server(interface_ip); 

    return 0; 
}   

