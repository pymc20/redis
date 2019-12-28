#include "Read.h"

Read::Read(int type, const char *key, Connect *connect)
{
    Read::type = type;
    Read::key = key;
    Read::redis_connect = connect;
};

Read::~Read()
{
    delete[] key;
    delete redis_connect;
};

int Read::execute()
{
    if(type == SCHEMA)
    {
        readSchemaList();
    }
    return 1;
};

int Read::readSchemaKeys()
{
    std::string query = "hkeys " + std::string(key) + "\r\n";
    redis_connect->redisSend(query.c_str());
    return 1;
}

int Read::readSchemaList()
{
    std::string query = "keys schema\r\n";
    redis_connect->redisSend(query.c_str());
    return 1;
}