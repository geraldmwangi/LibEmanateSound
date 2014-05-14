#ifndef TYPEFACTORY_H
#define TYPEFACTORY_H
#include "parameteredobject.h"
#include <vector>
using namespace std;
class TypeFactory
{
public:
    TypeFactory();
    ~TypeFactory();
    ParameteredObject* createParameteredObject(string name,string className,string typeName);

private:

    vector<ParameteredObject*> mObjectList;
};

#endif // TYPEFACTORY_H
