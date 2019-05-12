//server side//
#include <stdio.h>
#include <unistd.h>
#include <winsock2.h>//alternative for sys/socket.h. <sys/socket.h> makes available a type, socklen_t,
// which is an unsigned opaque integral type of length of at least 32 bits.//
#include <stdlib.h>
//#include <netinet/in.h>//constants and structures needed for domain addresses//
#include <string.h> 
#define PORT 8080// means connect to port 8080 of that web address.//
int main(int argc , char const *argv[])//argc stands for "argument count",argv stands for "argument vector".//
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt=1;
    int addrlen=sizeof(address);
    char buffer[1024]={0};
    char *hello="Hello from server";
    
    //socket file descriptor
    if ((server_fd=socket(AF_INET, SOCK_STREAM, 0))==0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    //attaching socket to prt 8080//
    if(setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT,&opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;//This field contains the address family 
    address.sin_addr.s_addr = INADDR_ANY;//This field contains the IP address.//.s_addr 
    address.sin_port = htons( PORT );//This field contains the port number.
    
    if(bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0)
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    valread = read( new_socket , buffer, 1024); 
    printf("%s\n",buffer ); 
    send(new_socket , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    return 0; 
}

