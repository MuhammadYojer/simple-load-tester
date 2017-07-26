#ifndef CONNECTOR_H_INCLUDED
#define CONNECTOR_H_INCLUDED
#include "connector.h"
#endif //CONNECTOR_H_INCLUDED

#include <netinet/in.h>

int get_socket(void);

void get_ip_address(char addr[]);

void establish_connection(int sock_id);
