#include "Redis.h"
#include "../Connect/Connect.h"

Redis::Redis(const char* addr, int port)
{
    Redis::redis_connect = new Connect(addr, port);
};

Redis::~Redis()
{
    delete Redis::redis_connect;
};

int Redis::isConnect()
{
    if( -1 == Redis::redis_connect->isConnect())
    {
        return -1;
    }
    else
    {
        return 1;
    }
};

Connect* Redis::getSocket()
{
    return redis_connect;
};

void Redis::redisConnect()
{
    redis_connect->redisConnect();
};