#include "Create.h"
#include "../Validation/Validation.h"
#include <string>

using namespace rapidjson;

Create::Create(int type, const char * json, Connect *connect)
{
    Create::type = type;
    Create::json = json;
    Create::redis_connect = connect;
};

int Create::execute()
{
    if(type == 1)
    {
        createSchemaByQuery();
    }
    return 1;
};

int Create::createSchemaByQuery()
{
    Validation *validation = new Validation();
    Document doc;
    doc.Parse(json);
    Value::ConstMemberIterator itr = doc.FindMember("nodeId");
    std::string nodeId;
    if (itr == doc.MemberEnd())
    {
        return -1;
    }
    else
    {
        nodeId = itr->value.GetString();
    }
    itr = doc.FindMember("parentId");
    if (itr != doc.MemberEnd())
    {
        if(!itr->value.IsString())
        {
            doc["parentId"] = "root";
        }
        else
        {
            if(validation->isStringEmpty(itr->value.GetString()) == -1)
                doc["parentId"] = "root";
        }
    }
    else
        doc.AddMember("parentId", "root", doc.GetAllocator());
    std::string blank = " ";
    std::string tempQuery = "hmset " + nodeId + blank;
    itr = doc.MemberBegin();
    for(;itr != doc.MemberEnd(); itr++)
    {
        tempQuery += itr->name.GetString() + blank + "\"" + itr->value.GetString() + "\"";
        if(itr != doc.MemberEnd())
            tempQuery += " ";
    }
    tempQuery += "\r\n";
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);
    redis_connect->redisSend(tempQuery.c_str());
    return 1;
};

int Create::createNodeByQuery()
{

    return 1;
};
