#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 1521 

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if ( sockfd == -1 ) {
    perror("HTTP Server (socket)");
    return 1;
  }
  printf("HTTP Server (socket) success\n");

  struct sockaddr_in addr;
  int addrlen = sizeof(addr);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;

  if ( bind(sockfd, (struct sockaddr *)&addr, addrlen) != 0 ) {
    perror("HTTP Server (bind)");
    return 1;
  }

  if ( listen(sockfd, SOMAXCONN) != 0 ) {
    perror("HTTP Server (listen)");
    return 1;
  }

  printf("HTTP Server (bind, listen) success\n");

  return 0;
}
