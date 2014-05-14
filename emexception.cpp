#include "emexception.h"




EmException::EmException(string name, string classname, string typeclass) throw()
{
    mMsg=name+":"+classname+":"+typeclass;

}

EmException::~EmException() throw()
{
}

const char *EmException::what() const throw()
{
    return mMsg.c_str();
}
