#ifndef SINUSMODULATOR_H
#define SINUSMODULATOR_H
#include <parametermodulator.h>
class SinusModulator:public ParameterModulator
{
public:
    SinusModulator(string name);

    // ParameterModulator interface
protected:
    virtual void initModulationTable();
};

#endif // SINUSMODULATOR_H
