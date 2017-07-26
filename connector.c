#include "connector.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>

int get_socket(void) {
    int socket_id;

    //Get a socket
	if((socket_id = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		fprintf(stderr,"Couldn't get a socket.\n");
		exit(EXIT_FAILURE);
	}else {
		fprintf(stderr,"Got a socket.\n");
	}

	return socket_id;
}

void get_ip_address(char addr[]) {
    struct hostent *hp;

    memset(&servaddr, 0, sizeof(servaddr));

	//get address
	if((hp = gethostbyname(addr)) == NULL) {
		fprintf(stderr,"Couldn't get an address.\n"); exit(EXIT_FAILURE);
	}else {
		fprintf(stderr,"Got an address.\n");
	}

	memcpy((char *)&servaddr.sin_addr.s_addr, (char *)hp->h_addr, hp->h_length);

	//port number and type
	servaddr.sin_port = htons(80);
	servaddr.sin_family = AF_INET;
}

void establish_connection(int sock_id) {
    //establish the connection
	if(connect(sock_id, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
		fprintf(stderr, "Couldn't connect.\n");
	}
	else {
		fprintf(stderr, "Got a connection.\n");
	}
}
