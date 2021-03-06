#include "Connect.h"

Connect::Connect(const char* addr, int port)
{
    Connect::addr = addr;
    Connect::port = port;
};

Connect::~Connect()
{
    disConnect();
}

int Connect::redisConnect()
{
    Connect::redis_socket = socket( PF_INET, SOCK_STREAM, 0);
    
    if( -1 == Connect::redis_socket)
    {
        printf("socket 생성 실패\n");
        Connect::connect_status = -1;
        return -1;
    }

    memset( &redis_server, 0, sizeof( redis_server ) );
    redis_server.sin_family     = AF_INET;
    redis_server.sin_port       = htons(port);
    redis_server.sin_addr.s_addr= inet_addr(addr);

    if(-1 == connect(redis_socket, (struct sockaddr*)&redis_server, sizeof(redis_server)))
    {
        printf("접속 실패\n");
        connect_status = -1;
        return -1;
    }
    return 1;
};

int Connect::isConnect()
{
    return connect_status;
};

std::string Connect::redisSend(const char* query)
{
    int length = strlen(query);
    char buff[65536];
    send(redis_socket, query, length, 0);
    printf("%s",query);
    recv(redis_socket, buff, BUFF_SIZE, 0);
    printf("%s", buff);
    std::string result = buff;
    return result;
};

int Connect::disConnect()
{   
    close(redis_socket);
    return 1;
};