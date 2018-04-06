//Imports Local
#include "server.h"
//Imports External
#include <sys/socket.h>
#include <fcntl.h>

int bind_socket(int sck_fd, short port)
{
  struct sockaddr_in specs;
  specs.sin_addr.s_addr = htonl(INADDR_ANY);
  specs.sin_port = htons(port);
  specs.sin_family = AF_INET;
  return bind(sck_fd, (struct sockaddr*)
    &specs, sizeof specs);
}

void configue_socket(int sck_fd)
{
  int yes = 1; int no = 0;
  int flags = fcntl(sck_fd, F_GETFL, 0);
  fcntl(sck_fd, F_SETFL, flags | O_NONBLOCK);
  setsockopt(sck_fd, SOL_SOCKET, SO_REUSEADDR,
    &yes, sizeof no);
}

void init_server()
{
  int err, socket_fd;
  //Reserve a Socket from OS
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(socket_fd<0) on_error("Socket Creation Fucked");
  //Enable re-use
  configue_socket(socket_fd);
  //Bind to Port&Addr
  err = bind_socket(socket_fd, 5555);
  if(err<0) on_error("Socket Binding Fucked");
  //Enable Listening
  listen(socket_fd, 32);
  //Dispatch Connections
  dispatch_connections(socket_fd);
}
