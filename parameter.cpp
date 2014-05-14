#include <parameter.h>



Parameter::Parameter(string name)
{
    mName=name;
}

string Parameter::getName()
{
    return mName;
}
