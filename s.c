



#include <netdb.h> 
#include <netinet/in.h>
#include <stdlib.h> 
#include <stdio.h>
#include <errno.h>//The <errno.h> header file defines the integer variable errno, which
       //is set by system calls and some library functions in the event of an
      // error to indicate what went wrong.

#include <unistd.h>
#include <arpa/inet.h>//The <arpa/inet.h> header makes available the type in_port_t and the type in_addr_t as defined in the description of <netinet/in.h>//
#include <sys/time.h>//FD_SET, FD_ISSET, FD_ZERO, .....
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h> // special interest: clock_t. 
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

////function for chat///
void func(int sockfd){
    char buff[MAX];
    int n;
    //infinte loop for chat//
    for(;;){
        bzero(buff, MAX);
        read(sockfd, buff, sizeof(buff));
        printf("from client: %s\t to client:",buff);
        
        bzero(buff, MAX);
        n=0;
        while((buff[n++]=getchar())!='\n');
        write(sockfd, buff, sizeof(buff));
        
        if(strncmp("exit",buff,4)==0){
            printf("server exit...\n");
            break;
        }
    }
}

///driver function///
int main(){
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd==-1){
        printf("socket creation failed.....\n");
        exit(0);
    }
    else
        printf("socket successfully created...\n");
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);///The htonl() function converts the unsigned integer hostlong from host byte order to network byte order.
    servaddr.sin_port=htons(PORT);
    
    if((bind(sockfd, (SA*)&servaddr, sizeof(servaddr)))!=0){
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("socket successfully binded..\n");
        
    if((listen(sockfd, 5))!=0){
        printf("listen failed...\n");
        exit(0);
    }
    else
        printf("server listening...\n");
    len=sizeof(cli);
    
    connfd=accept(sockfd, (SA*)&cli, &len);
    if(connfd<0){
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client....\n");
        
    func(connfd);
    close(sockfd);
}



