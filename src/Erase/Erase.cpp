#include "Erase.h"

Erase::Erase(int type, const char *key, Connect *redis_connect)
{
    Erase::type = type;
    Erase::key = key;
    Erase::redis_connect = redis_connect;
};

Erase::~Erase()
{
    delete[] key;
    delete redis_connect;
};

int Erase::execute()
{
    if(type == SCHEMA)
    {
        eraseSchema();
    }
    return 1;
};

int Erase::eraseSchema()
{
    std::string query = "del " + std::string(key);
    redis_connect->redisSend(query.c_str());
    return 1;
};