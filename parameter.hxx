#include "parameter.h"

template<class T>
TemplatedParameter<T>::TemplatedParameter(string name,T lowerbound, T upperbound, T val)
    :Parameter(name)
{
    mLowerBound=lowerbound;
    mUpperBound=upperbound;
    mMeanVal=val;
    mDeviation=0;
}
template<class T>
T TemplatedParameter<T>::operator*(TemplatedParameter<T> &rhs)
{
    return (mMeanVal+mDeviation)*rhs();
}
template<class T>
T TemplatedParameter<T>::operator*(T &rhs)
{
    return (mMeanVal+mDeviation)*rhs;
}
template<class T>
T TemplatedParameter<T>::operator/(TemplatedParameter<T> &rhs)
{
    return (mMeanVal+mDeviation)/rhs();
}
template<class T>
T TemplatedParameter<T>::operator/(T &rhs)
{
    return (mMeanVal+mDeviation)/rhs;
}
template<class T>
T TemplatedParameter<T>::operator+(TemplatedParameter<T> &rhs)
{
    return (mMeanVal+mDeviation)+rhs();
}
template<class T>
T TemplatedParameter<T>::operator+(T &rhs)
{
    return (mMeanVal+mDeviation)+rhs;
}
template<class T>
T TemplatedParameter<T>::operator-(TemplatedParameter<T> &rhs)
{
    return (mMeanVal+mDeviation)-rhs();
}

template<class T>
T TemplatedParameter<T>::operator-(T &rhs)
{
    return (mMeanVal+mDeviation)-rhs;
}

template<class T>
T TemplatedParameter<T>::operator()()
{
    return mMeanVal+mDeviation;
}
//template<class T>
//T TemplatedParameter<T>::operator=(T rhs)
//{
//    mVal=rhs;
//    return mVal;
//}

template<class T>
em_scalar TemplatedParameter<T>::operator=(em_scalar rhs)
{
    mMeanVal=(T)rhs;
}
template<class T>
em_scalar TemplatedParameter<T>::getMax()
{
    return (em_scalar)mUpperBound;
}

template<class T>
em_scalar TemplatedParameter<T>::getMin()
{
    return (em_scalar)mLowerBound;
}

template<class T>
em_scalar TemplatedParameter<T>::getMeanVal()
{
    return (em_scalar)mMeanVal;
}

template<class T>
void TemplatedParameter<T>::setDeviation(em_scalar deviation)
{
    if(mMeanVal+deviation>mUpperBound)
        deviation=mUpperBound-mMeanVal;
    if(mMeanVal+deviation<mLowerBound)
        deviation=mLowerBound-mMeanVal;
    mDeviation=deviation;
}
