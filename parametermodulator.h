#ifndef PARAMETERMODULATOR_H
#define PARAMETERMODULATOR_H
#include <EmanateTypes.h>
#include <parameter.h>
#include <parameteredobject.h>
#include <vector>
using namespace std;
class ParameterModulator: public ParameteredObject
{
private:
    em_integer mSamplerate;
    em_integer mPeriodBufSize;

    vector<Parameter*> mModulatedParameters;
    float curTablePos;
public:
    ParameterModulator(string name, string type);
    ~ParameterModulator();
    void initialize(em_integer samplerate,em_integer periodbufsize);
    void process();
    void finalize();
    void addModulatedParameter(Parameter* par);
    void removeModulatedParameter(Parameter* par);
    TemplatedParameter<float> frequency;
    TemplatedParameter<float> depth;
protected:
    virtual void initModulationTable()=0;
    int mModTableSize;
    float*  mModTable;
};

#endif // PARAMETERMODULATOR_H
