#ifndef _VALIDATION_H_
#define _VALIDATION_H_

class Validation
{
    public :
        int isStringEmpty(const char *string);
        int isJSON(const char *string);
        int isEqualsJSON(const char *firstJSON, const char *secondJSON);
        int isRequired();
};


#endif