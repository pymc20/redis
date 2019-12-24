#include "./Redis/Redis.h"

int main(int argc, char** argv)
{
    Redis* redis = new Redis("127.0.0.1", 6379);
    redis->redisConnect();
    Connect* redis_socket;
    if(-1 == redis->isConnect())
    {
        return 0;
    }
    else
    {
        redis_socket = redis->getSocket();
    }
    redis_socket->redisSend("ping\r\n");
    int result = redis->create(SCHEMA, "{\"parentId\": \"tt\",\"nodeId\":\"nodeId\"}");
    if(result == -1)
    {
        printf("실패");
    }
    else
    {
        printf("성공");
    }
    return 0;
}