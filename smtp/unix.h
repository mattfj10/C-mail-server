#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define on_error(...){fprintf(stderr,__VA_ARGS__); fprintf(stderr,"\n"); fflush(stderr);}
