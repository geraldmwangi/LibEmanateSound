#ifndef PARAMETER_H
#define PARAMETER_H
#include <EmanateTypes.h>
#include <string>
using namespace std;
class Parameter
{
public:
    Parameter(string name);
    string getName();
    virtual em_scalar operator=(em_scalar rhs)=0;
    virtual em_scalar getMax()=0;
    virtual em_scalar getMin()=0;
    virtual em_scalar getMeanVal()=0;
    virtual void setDeviation(em_scalar deviation)=0;
private:
    string mName;

};

template<class T>
class TemplatedParameter:public Parameter
{
public:
    TemplatedParameter(string name,T lowerbound,T upperbound, T val=0);
    T operator* (TemplatedParameter<T>& rhs);
    T operator* (T& rhs);
    T operator/ (TemplatedParameter<T>& rhs);
    T operator/ (T& rhs);
    T operator+ (TemplatedParameter<T>& rhs);
    T operator+ (T& rhs);
    T operator- (TemplatedParameter<T>& rhs);
    T operator- (T& rhs);
    T operator()();
//    T operator=(T rhs);
    virtual em_scalar operator=(em_scalar rhs);
    virtual em_scalar getMax();
    virtual em_scalar getMin();
    virtual em_scalar getMeanVal();
    virtual void setDeviation(em_scalar deviation);
private:
    T mMeanVal;
    T mDeviation; // For modulators, deviation from MeanVal
    T mLowerBound;
    T mUpperBound;
};

#endif // PARAMETER_H
