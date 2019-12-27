#ifndef _CREATE_H_
#define _CREATE_H_
#include <map>
#include <string>
#include "../../include/rapidjson/document.h"
#include "../../include/rapidjson/prettywriter.h"
#include "../Connect/Connect.h"
#include "../Common/CommonType.h"


class Create
{
    public :
        Create(int type, std::map<const char *, const char *> data);
        Create(int type, const char *json, Connect *connect, const char *schemaName = "");
        ~Create();
        int execute();
    private :
        int createSchemaByJSON();
        int createNodeByJSON();
        int type;
        const char *schemaName;
        const char *json;
        Connect *redis_connect;
};

#endif