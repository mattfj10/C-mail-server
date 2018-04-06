//Imports Local
#include "module.h"
//Imports External
#include <netinet/in.h>
#include <stdio.h>
//Defines
#define BUFFER_SIZE 512
//Structs
typedef struct wrap_conn {
  struct sockaddr_in specs;
  int client_fd;
} wrap_conn;
//Functions
void dispatch_connections();
void init_connection();
//Global State
socklen_t client_len;
wrap_conn* current;
list* clients;
