#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"

namespace HynLib {

#define THROW_EXCEPTION(e,m) (throw e(m,__FILE__,__LINE__))

class Exception : public Object
{
protected:
    char* m_message;
    char* m_location;

    void init(const char* msg,const char* file,int line);
public:
    Exception(const char* msg);
    Exception(const char* file,int line);
    Exception(const char* msg, const char* file, int line);

    Exception(const Exception& e);// 拷贝构造函数
    Exception& operator = (const Exception& e);// 赋值操作重载函数

    virtual const char* message() const;
    virtual const char* location() const;

    // 纯虚的虚构函数，C++规定但凡提供虚构函数都需要实现
    virtual ~Exception();//  = 0; // 去除能正常编译
};

class ArithmeticException : public Exception
{
public:
    ArithmeticException() : Exception(0){}
    ArithmeticException(const char* msg) : Exception(msg){}
    ArithmeticException(const char* file,int line) : Exception(file,line){}
    ArithmeticException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    ArithmeticException(const ArithmeticException& e) : Exception(e){}
    ArithmeticException& operator= (const ArithmeticException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};
class NullPointerException : public Exception
{
public:
    NullPointerException() : Exception(0){}
    NullPointerException(const char* msg) : Exception(msg){}
    NullPointerException(const char* file,int line) : Exception(file,line){}
    NullPointerException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    NullPointerException(const NullPointerException& e) : Exception(e){}
    NullPointerException& operator= (const NullPointerException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};
class IndexOutofBoundsException : public Exception
{
public:
    IndexOutofBoundsException() : Exception(0){}
    IndexOutofBoundsException(const char* msg) : Exception(msg){}
    IndexOutofBoundsException(const char* file,int line) : Exception(file,line){}
    IndexOutofBoundsException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    IndexOutofBoundsException(const IndexOutofBoundsException& e) : Exception(e){}
    IndexOutofBoundsException& operator= (const IndexOutofBoundsException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};
class NoEnoughMemoryException : public Exception
{
public:
    NoEnoughMemoryException() : Exception(0){}
    NoEnoughMemoryException(const char* msg) : Exception(msg){}
    NoEnoughMemoryException(const char* file,int line) : Exception(file,line){}
    NoEnoughMemoryException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e){}
    NoEnoughMemoryException& operator= (const NoEnoughMemoryException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidParameterException : public Exception
{
public:
    InvalidParameterException() : Exception(0){}
    InvalidParameterException(const char* msg) : Exception(msg){}
    InvalidParameterException(const char* file,int line) : Exception(file,line){}
    InvalidParameterException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    InvalidParameterException(const InvalidParameterException& e) : Exception(e){}
    InvalidParameterException& operator= (const InvalidParameterException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};

class InvalidOperationException : public Exception
{
public:
    InvalidOperationException() : Exception(0){}
    InvalidOperationException(const char* msg) : Exception(msg){}
    InvalidOperationException(const char* file,int line) : Exception(file,line){}
    InvalidOperationException(const char* msg,const char* file,int line) : Exception(msg,file,line){}

    InvalidOperationException(const InvalidOperationException& e) : Exception(e){}
    InvalidOperationException& operator= (const InvalidOperationException&e)
    {
        Exception::operator=(e);
        return *this;
    }
};

}

#endif // EXCEPTION_H
