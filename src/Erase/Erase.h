#ifndef _ERASE_H_
#define _ERASE_H_
#include <string>
#include "../Connect/Connect.h"

#define SCHEMA 1
#define NODE 2

class Erase
{
    public:
        Erase(int type, const char *key, Connect *redis_connect);
        ~Erase();
        int execute();
    private:
        int eraseSchema();
        int type;
        const char *key;
        Connect *redis_connect;
};

#endif