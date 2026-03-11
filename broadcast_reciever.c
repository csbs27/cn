#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	while(1) {
		int sockfd,opt=1;
		struct sockaddr_in server,client;
		char buffer[1024];
		socklen_t len;
		
		sockfd = socket(AF_INET,SOCK_DGRAM,0);
		server.sin_family = AF_INET;
		server.sin_port = htons(8080);
		server.sin_addr.s_addr = INADDR_ANY;
		
		setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
		bind(sockfd,(struct sockaddr*)&server,sizeof(server));
		len=sizeof(client);
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&len);
		printf("Broadcast message: %s\n",buffer);
		close(sockfd);
	}
}
