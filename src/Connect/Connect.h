#ifndef _CONNECT_H_
#define _CONNECT_H_
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <string>
#define BUFF_SIZE 4096


class Connect
{
    public :
        Connect(const char* addr, int port);
        ~Connect();
        int isConnect();
        int redisConnect();
        int disConnect();
        std::string redisSend(const char* query);
    private :
        const char* addr;
        int port;
        int connect_status;
        int redis_socket;
        struct sockaddr_in redis_server;
};
#endif