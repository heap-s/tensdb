/*
    Move this to tensclient folder
*/

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define PORT 3030
#define SA struct sockaddr

void clientLoop(int sockfd) {
    char buffer[BUF_SIZE];
    int n;
    for(;;){
        bzero(buffer, BUF_SIZE);
        printf("tens > ");
        n = 0;
        while((buffer[n++] = getchar()) != '\n')
          ;
        write(sockfd, buffer, sizeof(buffer));
        bzero(buffer, BUF_SIZE);
        read(sockfd, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        if ((strncmp(buffer, "exit", 4) == 0) || (strncmp(buffer, "quit", 4) == 0)){
          printf("Goodbye!\n");
          break;
        }
    }
}

void clientStart(){
  int sockfd;
  struct sockaddr_in serv_addr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if(connect(sockfd, (SA*)&serv_addr, sizeof(serv_addr)) != 0){
    perror("Connection with the server failed");
    exit(EXIT_FAILURE);
  }

  clientLoop(sockfd);
  close(sockfd);
}
