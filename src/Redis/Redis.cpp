#include "Redis.h"
#include "../Connect/Connect.h"

Redis::Redis(const char* addr, int port)
{
    redis_connect = new Connect(addr, port);
};

Redis::~Redis()
{
    delete redis_connect;
};

int Redis::isConnect()
{
    if( -1 == redis_connect->isConnect())
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

int Redis::create(int type, const char *json)
{
    Create *create = new Create(SCHEMA, json, redis_connect);
    create->execute();
    return 1;
};