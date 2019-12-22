#include "./Redis/Redis.h"

int main(int argc, char** argv)
{
    Redis* redis = new Redis("127.0.0.1", 6379);
    redis->redisConnect();
    Connect* redis_socket;
    if(-1 == redis->isConnect())
    {
        printf("test1\n");
        return 0;
    }
    else
    {
        printf("test2\n");
        redis_socket = redis->getSocket();
    }
    redis_socket->redisSend("ping\r\n");
    return 0;
}