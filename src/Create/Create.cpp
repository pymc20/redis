#include "Create.h"

Create::Create(int type, const char* query, int redis_socket)
{
    Create::type = type;
    Create::query = query;
    Create::redis_socket = redis_socket;
};

int Create::run()
{
    int type = Create::type;
    if(type == 1) {
        Create::createSchemaByQuery(Create::query);
    } else if(type == 2) {
        Create::createNodeByQuery(Create::query);
    }
};

int Create::createSchemaByQuery(const char* query)
{
    Create::redis_socket;
};

int Create::createNodeByQuery(const char* query)
{

};