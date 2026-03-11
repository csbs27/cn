#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

    int sockfd;
    struct sockaddr_in group;
    char message[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    group.sin_family = AF_INET;
    group.sin_port = htons(8080);
    group.sin_addr.s_addr = inet_addr("239.0.0.1");

    while(1)
    {
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        sendto(sockfd, message, strlen(message), 0,
            (struct sockaddr*)&group, sizeof(group));
    }

    close(sockfd);
}
