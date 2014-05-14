#include "EmanateTools.h"

string stringToLowerCase(string str)
{
    string res=str;
    string::iterator it=str.begin();
    string::iterator itout=res.begin();
    for(;it!=str.end();it++)
    {
        *itout=tolower(*it);
    }
}
