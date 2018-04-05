#include "unix.h"

#define BUFFER_SIZE 512

void dispatch_connections();
void init_connection();
void init_server();

typedef struct list{
    void* ref;
    struct list* next;
 } list;

list* create_entry(void* location, list* next);
list* prepend(list* head, void* location);
list* append(list* head, void* location);

struct wrap_conn {
  struct sockaddr_in specs;
  int client_fd;
} wrap_conn;
