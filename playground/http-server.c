#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 1521 
#define BUFFER_SIZE 1024

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  char buffer[BUFFER_SIZE];
  char resp[] = "HTTP/1.0 200 OK\r\n"
    "Server: webserver-c\r\n"
    "Content-type: text/html\r\n\r\n"
    "<html>hello, world</html>\r\n";

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

  for (;;) {
    int connsockfd = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)&addrlen);

    if ( connsockfd < 0 ) {
      perror("HTTP Server (accept)");
      continue;
    }
    printf("Accepted Connection");

    // Read data from requests
    int valread = read(connsockfd, buffer, BUFFER_SIZE);
    if ( valread < 0 ) {
      perror("HTTP Server (read)");
      continue;
    }

    if ( write(connsockfd, resp, strlen(resp)) < 0 ) {
      perror("HTTP Server (write)");
      continue;
    }    

    close(connsockfd);
  }

  return 0;
}
