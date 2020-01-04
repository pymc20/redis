#include "Create.h"
#include "../Validation/Validation.h"

using namespace rapidjson;

Create::Create(int type, const char * json, Connect *connect, const char *schemaName)
{
    Create::type = type;
    Create::schemaName = schemaName;
    Create::json = json;
    Create::redis_connect = connect;
};

Create::~Create()
{
    delete redis_connect;
    delete schemaName;
    delete json;
}

int Create::execute()
{
    if(type == SCHEMA)
    {
        createSchemaByJSON();
    }
    else if(type == NODE)
    {
        createNodeByJSON();
    }
    return 1;
};

int Create::createSchemaByJSON()
{
    Validation *validation = new Validation();
    Document doc;
    doc.Parse(json);
    std::string schemaId;
    Value::ConstMemberIterator itr = doc.MemberEnd();
    if(validation->isStringEmpty(schemaName) == -1)
    {
        itr = doc.FindMember("schemaId");
        if (itr == doc.MemberEnd())
        {
            return -1;
        }
        else
            schemaId = itr->value.GetString();
    }
    else
        schemaId = schemaName;
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
    std::string tempQuery = "hmset " + schemaId + blank;
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
    std::string schemaListQuery = "linsert schema " + schemaId + "\r\n";
    redis_connect->redisSend(schemaListQuery.c_str());
    return 1;
};

int Create::createNodeByJSON()
{
    // Validation *validation = new Validation();
    Document doc;
    doc.Parse(json);
    Value::ConstMemberIterator itr = doc.MemberBegin();
    std::map<std::string,std::string> json_to_map;
    for(;itr != doc.MemberEnd(); itr++)
    {
        json_to_map.insert(std::pair<std::string,std::string>(itr->name.GetString(),itr->value.GetString()));
    }
    return 1;
};
