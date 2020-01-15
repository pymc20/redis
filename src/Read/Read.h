#ifndef _READ_H_
#define _READ_H_
#include <string>
#include "../Connect/Connect.h"
#include "../Common/CommonType.h"

class Read
{
    public :
        Read(int type, const char *key, Connect *connect);
        ~Read();
        int execute();
    private :
        int type;
        const char *key;
        Connect *redis_connect;
        int readSchemaKeys();
        int readSchemaList();
        std::string readSchema();
};

#endif