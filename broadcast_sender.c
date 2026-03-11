#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
	
	while(1) {
		int sockfd,opt=1;
		struct sockaddr_in server;
		char buffer[1024];
		socklen_t len;

		printf("Enter message: ");
		fgets(buffer, sizeof(buffer), stdin);
		
		server.sin_family = AF_INET;
		server.sin_port = htons(8080);
		server.sin_addr.s_addr = inet_addr("255.255.255.255"); //or 192.168.1.255
		
		sockfd = socket(AF_INET,SOCK_DGRAM,0);
		setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&opt,sizeof(opt));

		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server));
		close(sockfd);
		printf("Broadcast successfully sent\n");
	}
}
