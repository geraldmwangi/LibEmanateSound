#include "parameteredobject.h"



ParameteredObject::ParameteredObject(string name, string className, string type)
{
    mName=name;
    mClass=className;
    mType=type;
}

ParameteredObject::~ParameteredObject()
{
}

void ParameteredObject::addParameter(Parameter& par)
{
    mParameters.insert(pair<string,Parameter&>(par.getName(),par));
}

string ParameteredObject::getName()
{
    return mName;
}

string ParameteredObject::getClass()
{
    return mClass;
}

string ParameteredObject::getType()
{
    return mType;
}


