#include "connector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
	int socket_id;
	char message[1024 * 1024];

	//set up the connection
	socket_id = get_socket();
	get_ip_address("website.com");
	establish_connection(socket_id);

	//HTTP
	char request[] = "GET / HTTP/1.1\r\n" "Host: website.com\r\n" "From: ...\r\n\r\n";
	fprintf(stderr, "\nREQUEST PACKET: \n");
    fprintf(stderr, request);

	//send the request
	while(1) {
        sleep(1);
        write(socket_id, request, strlen(request));
        read(socket_id, message, 1024 * 1024);
	}

	return 0;
}
