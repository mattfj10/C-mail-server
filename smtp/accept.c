#include "server.h"

list* clients;
socklen_t client_len;
struct wrap_conn* current;
void new_connection(int sck_fd)
{
  //If Strucure in Use, allocate new struct
  if(current->specs.sin_family != AF_INET)
    current = (struct wrap_conn*) malloc(sizeof(wrap_conn));
  //Non-Blocking Accept into Structure
  current->client_fd = accept(sck_fd, (struct sockaddr*)
    &current->specs, &client_len);
  //Should Have Error Handling
  if(current->client_fd<0) usleep(1000*1000);
  else init_connection();
  //Because I'm a Nigger
  new_connection(sck_fd);
}

void dispatch_connections(int sck_fd)
{
  //Remeber Kids, always init global pointers.
  current = (struct wrap_conn*) malloc(sizeof(wrap_conn));
  client_len = sizeof(struct sockaddr_in);
  new_connection(sck_fd);
}

void init_connection()
{
  append(clients, current);
  printf("Addr: %s",
    inet_ntoa(current->specs.sin_addr)
  );
}
