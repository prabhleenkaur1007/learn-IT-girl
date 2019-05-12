#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
//#include <arpa inet.h>
//#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main (int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock=0,valread;
    struct sockaddr_in serv_addr;
    char *hello = "hello from client";
    char buffer[1024] = {0};
    if((sock=socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        perror("Socket creation error \n");
        exit(EXIT_FAILURE);
    }
    
    memset(&serv_addr, '0',sizeof(serv_addr));
    //void* memset( void* str, int ch, size_t n);
 //Parameters
 //str[] : Pointer to the object to copy the character.
 //ch : The character to copy.
 //n : Number of bytes to copy.
 
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port= htons(PORT);
    
    if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0){
        printf("\n invalid address\n");
        return -1;
    }
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
        printf("\nconnection failed\n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    valread = read( sock , buffer, 1024); 
    printf("%s\n",buffer ); 
    return 0;
}