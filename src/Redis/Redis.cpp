#include "Redis.h"
#include "../Connect/Connect.h"

Redis::Redis(const char* addr, int port)
{
    redis_connect = new Connect(addr, port);
};

Redis::~Redis()
{
    redis_connect->disConnect();
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

const char *Redis::createQuery(int type, const char *json)
{
    Create *create = new Create(SCHEMA, json);
    return create->getQuery();
};