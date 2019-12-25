#include "Redis.h"
#include "../Connect/Connect.h"

Redis::Redis(const char* addr, int port)
{
    redis_connect = new Connect(addr, port);
    redis_connect->redisConnect();
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

int Redis::create(int type, const char *json)
{
    Create *create = new Create(type, json, redis_connect);
    create->execute();
    return 1;
};

int Redis::read(int type, const char *key)
{
    Read *read = new Read(type, key, redis_connect);
    read->execute();
    return 1;
}

int Redis::erase(int type, const char *key)
{
    Erase *erase = new Erase(type, key, redis_connect);
    erase->execute();
    return 1;
}