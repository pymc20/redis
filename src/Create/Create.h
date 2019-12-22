#ifndef _CREATE_H_
#define _CREATE_H_

#define SCHEMA 1
#define NODE 2

class Create
{
    public :
        Create(int type, const char* query, int redis_socket);
        int run();
        int createSchemaByQuery(const char* query);
        int createNodeByQuery(const char* query);
    private :
        int type;
        const char* query;
        int redis_socket;
};

#endif