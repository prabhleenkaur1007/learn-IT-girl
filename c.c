///learnt from geek for grrks, stackoverflow, etc. 
// telnet localhost 4950 can also be a host///////
#include <netdb.h>//The <netdb.h> header may make available the type in_port_t and the type in_addr_t as defined in the description of <netinet/in.h>. //
#include <stdio.h>//The stdio.h header defines three variable types, several macros, and various functions for performing input and output.//
#include <stdlib.h>//includes functions involving memory allocation, process control, conversions and others//
////// while “<stdio.h>” contains header information for 'File related Input/Output' functions, “<stdlib.h>” contains header information for 'Memory Allocation/Freeing' functions./////
#include <string.h>
#include <sys/socket.h>//The <sys/socket.h> header shall define the type socklen_t, which is an integer type of width of at least 32 bits;//
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
///function for infinite loop
void func(int sockfd){
    char buff[MAX];
    int n;
    for(;;){
        bzero(buff, sizeof(buff));
        printf("enter the string: ");
        n=0;
        while((buff[n++]=getchar())!='\n');
        write(sockfd, buff, sizeof(buff));
        
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("from server: %s", buff);
        if((strncmp(buff, "exit", 4))==0){
            printf("client exit...\n");
            break;
        }
    }
}

int main(){
    int sockfd,connfd;
    struct sockaddr_in servaddr, cli;
    
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd==-1){
        printf("socket creation failed...\n");
        exit(0);
    }else
        printf("socket successfully created...\n");
    bzero(&servaddr, sizeof(servaddr));
    
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    servaddr.sin_port=htons(PORT);
    
    if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr))!=0){
        printf("connection with server failed...\n");
        exit(0);
    }
    else
        printf("connected to server..\n");
        
    func(sockfd);
    close(sockfd);
    
}














