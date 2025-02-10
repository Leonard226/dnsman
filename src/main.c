#include <stdio.h>
#include "../include/interfaces.h"

int main() {
    printf("Listing active network interfaces:\n");
    list_active_interfaces(); 
    return 0; 
}