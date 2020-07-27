#ifndef HSTRING_H
#define HSTRING_H

#include "Object.h"

namespace HynLib{

class HString : public Object{
protected:
    char* m_str;
    int m_length;
    void init(const char* s);
public:
    HString();
    ~HString();
    HString(char c);
    HString(const char* c);
    HString(const HString& s);

    int length() const;
    const char* str() const;

    bool operator == (const HString& s) const;
    bool operator == (const char* s) const;
    bool operator != (const HString& s) const;
    bool operator != (const char* s) const;
    bool operator > (const HString& s) const;
    bool operator > (const char* s);
    bool operator < (const HString& s) const;
    bool operator < (const char* s) const;
    bool operator >= (const HString& s) const;
    bool operator >= (const char* s) const;
    bool operator <= (const HString& s) const;
    bool operator <= (const char* s) const;
    HString operator + (const HString& s) const;
    HString operator + (const char* s) const;
    HString& operator += (const HString& s);
    HString& operator += (const char* s);

    HString& operator = (const HString& s);
    HString& operator = (const char* s);
    HString& operator = (const char c);
};
}

#endif //HSTRING_H
