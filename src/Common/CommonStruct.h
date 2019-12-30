#ifndef _H_COMMON_STRUCT_
#define _H_COMMON_STRUCT_
#include <vector>
#include <utility>
#include <string>

class Node
{
    public :
        Vector::iterator begin();
        Vector::iterator end();

    private :
        Vector<pair<string, int> intValue;
        Vector<pair<string, string> stringValue;
};

#endif