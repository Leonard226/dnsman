#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <net/if.h>
#include "../include/interfaces.h"

/*
This method retrieves a linked list of all network interfaces and their attributes
*/

void list_active_interfaces() {
    // ifaddrs holds head of network interfaces linked list, ifa used to iterate
    struct ifaddrs *ifaddr, *ifa;
    char ip[INET6_ADDRSTRLEN]; 

    // get the list of network interfaces
    if (getifaddrs(&ifaddr) == -1) {
        exit(EXIT_FAILURE);
    }

    // iterate through linked list
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue; 
        if (!(ifa->ifa_flags & IFF_UP)) continue; 

        // check if interface is IPv4 or IPv6 address
        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr; 
            inet_ntop(AF_INET, &addr->sin_addr, ip, sizeof(ip)); 
            printf("Interface: %s, IPv4 Address: %s\n", ifa->ifa_name, ip); 
        }
        if (ifa->ifa_addr->sa_family == AF_INET6) {
            struct sockaddr_in6 *addr = (struct sockaddr_in6 *)ifa->ifa_addr; 
            inet_ntop(AF_INET6, &addr->sin6_addr, ip, sizeof(ip)); 
            printf("Interface: %s, IPv6 Address: %s\n", ifa->ifa_name, ip); 
        }
    }

    freeifaddrs(ifaddr); 
    
}