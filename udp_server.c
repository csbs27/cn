#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	while(1) {
		int sockfd;
		struct sockaddr_in server,client;
		socklen_t len;
		char  buffer[1024];
		
		server.sin_family = AF_INET;
		server.sin_port = htons(8080);
		server.sin_addr.s_addr=INADDR_ANY;
		sockfd=socket(AF_INET,SOCK_DGRAM,0);
		bind(sockfd,(struct sockaddr*)&server,sizeof(server));
		
		printf("Waiting for Connection\n");
		len=sizeof(client);
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&len);
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,len);
		printf("Client: %s\n",buffer);
	close(sockfd);
	}
}