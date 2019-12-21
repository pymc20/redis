#include "Connect.h"

Connect::Connect(const char* addr, int port)
{
    struct sockaddr_in redis_server;

    Connect::redis_socket = socket( PF_INET, SOCK_STREAM, 0);
    
    if( -1 == Connect::redis_socket)
    {
        printf("socket 생성 실패\n");
        exit(1);
    }

    memset( &redis_server, 0, sizeof( redis_server ) );
    redis_server.sin_family     = AF_INET;
    redis_server.sin_port       = htons(port);
    redis_server.sin_addr.s_addr= inet_addr(addr);

    if(-1 == connect(redis_socket, (struct sockaddr*)&redis_server, sizeof(redis_server)))
    {
        printf("접속 실패\n");
        exit(1);
    }

};