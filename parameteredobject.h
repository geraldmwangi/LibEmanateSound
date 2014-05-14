#ifndef PARAMETEREDOBJECT_H
#define PARAMETEREDOBJECT_H
#include <string>
#include <parameter.h>
#include <vector>
#include <map>
#include "EmanateTypes.h"
using namespace std;
class ParameteredObject
{
public:
    ParameteredObject(string name, string className,string type);
    virtual ~ParameteredObject();
    string getName();
    string getClass();
    string getType();
private:
    /* Name of object*/
    std::string mName;

    /* Class of parent, e.g WaveTable, STFT*/
    std::string mClass;

    /* Class type: e.g Sine, Box, Triangle Wavetable*/
    std::string mType;
    map<string, Parameter&> mParameters;
protected:
    void addParameter(Parameter &par);
};

#endif // PARAMETEREDOBJECT_H
