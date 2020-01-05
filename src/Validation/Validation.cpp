#include "Validation.h"
#include <string.h>
#include <stdio.h>

int Validation::isStringEmpty(const char *string)
{
    int length = strlen(string);
    if(length == 0)
        return -1;
    char temp[length];
    memset(temp, 0, sizeof(temp));
    int tempIdx = 0;
    for(int idx=0; idx < length; idx++)
    {
        if(string[idx] != ' ')
        {
            temp[tempIdx] = string[idx];
            tempIdx++;
        }
    }
    if(temp == string)
    {
        return 1;
    }
    else
    {
        return -1;
    }
};

int Validation::isJSON(const char *String)
{
    return 1;
};

int Validation::isEqualsJSON(const char *firstJSON, const char *secondJSON)
{
    return 1;
}