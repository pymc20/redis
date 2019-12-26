#include "Update.h"

using namespace rapidjson;

Update::Update(int type, const char *json, Connect *redis_connect, const char *schemaName)
{
    Update::type = type;
    Update::json = json;
    Update::redis_connect = redis_connect;
    Update::schemaName = schemaName;
};

Update::~Update()
{
    delete[] json;
    delete redis_connect;
};

int Update::execute()
{
    if(type == SCHEMA)
    {
        updateSchema();
    }
    return 1;
};

int Update::updateSchema()
{
    Document doc;
    doc.Parse(json);
    std::string query = "hmset ";
    std::string blank = " ";
    if(schemaName == "")
    {
        Value::ConstMemberIterator itr = doc.FindMember("nodeId");
        if (itr == doc.MemberEnd())
        {
            printf("Not Found Schema\n");
            return -1;
        }
        else
            query += itr->value.GetString() + blank;
    }
    else
    {
        query += schemaName + blank;
        for(auto& v : doc.GetObject())
        {
            query += v.name.GetString() + blank + v.value.GetString() + blank;
        }
    }
    query += "\r\n";
    redis_connect->redisSend(query.c_str());
    return 1;
};