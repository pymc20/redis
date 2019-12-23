#include "Create.h"
#include <string>

using namespace rapidjson;

Create::Create(int type, const char * json)
{
    Create::type = type;
    Create::query = json;
};

const char *Create::getQuery()
{
    if(type == 1)
    {
        createSchemaByQuery();
    }
    return query;
};

int Create::createSchemaByQuery()
{
    Document doc;
    doc.Parse(query);
    Value::ConstMemberIterator itr = doc.FindMember("nodeId");
    std::string nodeId;
    if (itr == doc.MemberEnd())
    {
        printf("return\n");
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
    query = tempQuery.c_str();
    return 1;
};

int Create::createNodeByQuery()
{

    return 1;
};
