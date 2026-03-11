#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	while(1) {
		int sockfd;
		struct sockaddr_in server;
		socklen_t len;
		char buffer[1024];

		printf("Enter message: ");
		fgets(buffer, sizeof(buffer), stdin);
		
		sockfd = socket(AF_INET,SOCK_DGRAM,0);
		server.sin_family=AF_INET;
		server.sin_port=htons(8080);
		server.sin_addr.s_addr = inet_addr("127.0.0.1");
		
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server));
		printf("Sent request to server\n");
		len = sizeof(server);
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,&len);
		printf("Server: %s\n",buffer);
		close(sockfd);
	}
}