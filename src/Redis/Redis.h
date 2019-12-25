#ifndef _REDIS_H_
#define _REDIS_H_
#include "../Common/CommonType.h"
#include "../Connect/Connect.h"
#include "../Create/Create.h"
#include "../Read/Read.h"
#include "../Erase/Erase.h"


class Redis
{
    public :
        Redis(const char* addr, int port);
        ~Redis();
        int isConnect();
        int create(int type, const char* json);
        int read(int type, const char *key);
        int update();
        int erase(int type, const char *key);
    private :
        Connect* redis_connect;
};


#endif