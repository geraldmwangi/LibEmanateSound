#ifndef EMEXCEPTION_H
#define EMEXCEPTION_H
#include <exception>
#include <string>
using namespace std;
class EmException : public exception
{
    string mMsg;
public:
    EmException(string name,string classname,string typeclass) throw();
    ~EmException() throw();
    virtual const char* what() const throw();
};

#endif // EMEXCEPTION_H
