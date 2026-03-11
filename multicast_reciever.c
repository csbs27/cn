#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    int sockfd,opt=1;
    struct sockaddr_in local;
    struct ip_mreq mreq;
    char buffer[1024];
    socklen_t len;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    local.sin_family = AF_INET;
    local.sin_port = htons(8080);
    local.sin_addr.s_addr = INADDR_ANY;

	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    bind(sockfd, (struct sockaddr*)&local, sizeof(local));

    mreq.imr_multiaddr.s_addr = inet_addr("239.0.0.1");
    mreq.imr_interface.s_addr = INADDR_ANY;

    setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP,
               &mreq, sizeof(mreq));

    while(1)
    {
        recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
}
