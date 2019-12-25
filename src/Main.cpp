#include "./Redis/Redis.h"

int main(int argc, char** argv)
{
    Redis* redis = new Redis("127.0.0.1", 6379);
    if(-1 == redis->isConnect())
    {
        return 0;
    }
    int result = redis->create(SCHEMA, "{\"parentId\": \"tt\",\"nodeId\":\"nodeId\"}");
    redis->read(SCHEMA, "nodeId");
    if(result == -1)
    {
        printf("실패\n");
    }
    else
    {
        printf("성공\n");
    }
    return 0;
}