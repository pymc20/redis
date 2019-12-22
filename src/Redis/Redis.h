#ifndef _REDIS_H_
#define _REDIS_H_
#include "../Connect/Connect.h"
#include "../Create/Create.h"

class Redis
{
    public :
        Redis(const char* addr, int port);
        ~Redis();
        void redisConnect();
        Connect* getSocket();
        int isConnect();
        int create(int type, const char* query);
        int read();
        int update();
        int erase();
    private :
        Connect* redis_connect;
};


#endif