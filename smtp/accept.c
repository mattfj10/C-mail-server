//Imports Local
#include "server.h"
//Imports External
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void new_connection(int sck_fd)
{
  //If Strucure in Use, allocate new struct
  if(current->specs.sin_family != AF_INET)
    current = (wrap_conn*) malloc(sizeof(wrap_conn));
  //Non-Blocking Accept into Structure
  current->client_fd = accept(sck_fd, (struct sockaddr*)
    &current->specs, &client_len);
  //Should Have Error Handling
  if(current->client_fd<0) usleep(100*1000);
  else init_connection();
  //Because I'm a Nigger
  new_connection(sck_fd);
}

void dispatch_connections(int sck_fd)
{
  //Remeber Kids, always init global pointers.
  current = (wrap_conn*) malloc(sizeof(wrap_conn));
  client_len = sizeof(struct sockaddr_in);
  //Event Loop (Init Connections, Send Data, Read Data)
  new_connection(sck_fd);
}

void init_connection()
{
  char str[INET_ADDRSTRLEN];
  clients = append(clients, current);
  wrap_conn* working = skip(clients,0);
  printf("Wrap Conn: %p\n", working);
  inet_ntop(AF_INET, &working->specs.sin_addr, str, INET_ADDRSTRLEN);
  printf("Addr: %s\n",str);
}
