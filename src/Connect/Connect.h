#ifndef _CONNECT_H_
#define _CONNECT_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

class Connect
{
    public :
        Connect(const char* addr, int port);
    private :
        int redis_socket;
};
#endif