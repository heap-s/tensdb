#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 3030
#define BUF_SIZE 1024
#define SA struct sockaddr

void serverLoop(int connfd) {
	char buff[BUF_SIZE];
	int n;

	for (;;) {
		bzero(buff, BUF_SIZE);

		read(connfd, buff, sizeof(buff));

		printf("From client: %s\t To client: ", buff);
		bzero(buff, BUF_SIZE);
		n = 0;

		while ((buff[n++] = getchar()) != '\n')
			;

		write(connfd, buff, sizeof(buff));

		if (strncmp("exit", buff, 4) == 0 || strncmp("quit", buff, 4) == 0)
			break;
	}
}

void startServer() {
	int sockfd, connfd;
	socklen_t len;
	struct sockaddr_in serv_addr, cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("Socket creation failed");
		exit(0);
	}
	bzero(&serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(PORT);

	if (bind(sockfd, (SA*)&serv_addr, sizeof(serv_addr)) != 0) {
		perror("Socket bind failed");
		exit(0);
	}

	if (listen(sockfd, 5) != 0) {
		perror("Socket listen failed");
		exit(0);
	}

	len = sizeof(cli_addr);

	connfd = accept(sockfd, (SA*)&cli_addr, &len);
	if (connfd < 0) {
		perror("Server accept failed");
		exit(0);
	}
	serverLoop(connfd);
	close(connfd);
	close(sockfd);
}
