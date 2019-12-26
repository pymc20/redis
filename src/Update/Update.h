#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <string>
#include "../Connect/Connect.h"
#include "../../include/rapidjson/document.h"
#include "../../include/rapidjson/prettywriter.h"
#include "../Common/CommonType.h"

class Update
{
    public :
        Update(int type, const char *json, Connect *redis_connect, const char *schemaName="");
        ~Update();
        int execute();
    private :
        int type;
        const char *json;
        Connect *redis_connect;
        const char *schemaName;
        int updateSchema();
};

#endif