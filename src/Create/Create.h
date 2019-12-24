#ifndef _CREATE_H_
#define _CREATE_H_
#include <map>
#include "../../include/rapidjson/document.h"
#include "../../include/rapidjson/prettywriter.h"
#include "../Connect/Connect.h"

#define SCHEMA 1
#define NODE 2

class Create
{
    public :
        Create(int type, std::map<const char *, const char *> data);
        Create(int type, const char *json, Connect *connect);
        int execute();
        int createSchemaByQuery();
        int createNodeByQuery();
    private :
        int type;
        const char *json;
        Connect *redis_connect;
};

#endif