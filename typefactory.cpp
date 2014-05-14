#include "typefactory.h"
#include "sinustable.h"
#include "sawtable.h"
#include "squaretable.h"
#include "sinusmodulator.h"
#include "emanation.h"
#include "listener.h"
#include <algorithm>
#include "EmanateTools.h"
TypeFactory::TypeFactory()
{
}

TypeFactory::~TypeFactory()
{
    for(int i=0;i<mObjectList.size();i++)
        delete mObjectList[i];
}

ParameteredObject* TypeFactory::createParameteredObject(string name, string className, string typeName)
{
    ParameteredObject* res=0;
    className=stringToLowerCase(className);
    typeName=stringToLowerCase(typeName);
    if(className=="wavetable")
    {
        if(typeName=="sinustable")
            res=new SinusTable(name);
        else if(typeName=="sawtable")
            res=new SawTable(name);
        else if(typeName=="squaretable")
            res=new SquareTable(name);

    }
    else if(className=="parametermodulator")
    {
        if(typeName=="sinusmodulator")
            res=new SinusModulator(name);
    }
    else if(className=="emanation")
        res=new Emanation(name);
    else if(className=="listener")
        res=new Listener(name);
    return res;
}
