#include "parametermodulator.h"


#define BASE_FREQ 0.01f

ParameterModulator::ParameterModulator(string name,  string type)
    :frequency("frequency",BASE_FREQ,5000,0),depth("depth",0,1,0),ParameteredObject(name,"ParameterModulator",type)
{

}

ParameterModulator::~ParameterModulator()
{
    finalize();


}

void ParameterModulator::initialize(em_integer samplerate, em_integer periodbufsize)
{
    mSamplerate=samplerate;
    mPeriodBufSize=periodbufsize;
    mModTableSize=mSamplerate/(BASE_FREQ*periodbufsize);
    if(mModTableSize!=0)
    {
        mModTable=new em_scalar[mModTableSize];
    }
    memset(mModTable,0,mModTableSize*sizeof(em_scalar));
    initModulationTable();
    curTablePos=0;
}

void ParameterModulator::process()
{
    int intPos=curTablePos;
    em_scalar delta=curTablePos-intPos;
    em_scalar val=(mModTable[intPos]+delta*(mModTable[(intPos==mModTableSize-1)?0:(intPos+1)]-mModTable[intPos])
            +delta*delta*(mModTable[(intPos==0)?(mModTableSize-1):(intPos-1)]+mModTable[(intPos==mModTableSize-1)?0:(intPos+1)]-2*mModTable[intPos]));

    for(int i=0;i<mModulatedParameters.size();i++)
    {
        Parameter* par=mModulatedParameters[i];
        em_scalar max=par->getMax();
        em_scalar min=par->getMin();

        (*par).setDeviation(depth()*(max-min)*(val));

    }
    curTablePos+=frequency()/BASE_FREQ;

    if(curTablePos>=mModTableSize)
    {
        curTablePos=0;

    }


}

void ParameterModulator::finalize()
{
    if(mModTable)
    {
        delete [] mModTable;
        mModTable=0;
        mModTableSize=0;
    }
}

void ParameterModulator::addModulatedParameter(Parameter *par)
{
    mModulatedParameters.push_back(par);
}

void ParameterModulator::removeModulatedParameter(Parameter *par)
{
    vector<Parameter*> tmp;
    for(int i=0;i<mModulatedParameters.size();i++)
    {
        if(mModulatedParameters[i]!=par)
            tmp.push_back(mModulatedParameters[i]);
    }
    mModulatedParameters=tmp;
    par->setDeviation(0);
}
