#ifndef HSTRING_H
#define HSTRING_H

#include "Object.h"

namespace HynLib{

class HString : public Object{
protected:
    char* m_str;
    int m_length;
    void init(const char* s);

    bool equal(const char* l,const char* r,int len) const;
    static int* make_pmt(const char* p);
    static int kmp(const char* s, const char* p);
public:
    HString();
    ~HString();
    HString(char c);
    HString(const char* c);
    HString(const HString& s);

    int length() const;
    const char* str() const;

    char& operator [] (int i);
    char operator [] (int i) const ;

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
    HString operator - (const HString& s) const;
    HString operator - (const char* s) const;
    HString& operator -= (const HString& s);
    HString& operator -= (const char* s);

    HString& operator = (const HString& s);
    HString& operator = (const char* s);
    HString& operator = (const char c);

    bool startWith(const HString& s) const;
    bool startWith(const char* s) const ;
    bool endWith(const HString& s) const ;
    bool endWith(const char* s) const;
    HString& insert(int i, const char* s);
    HString& insert(int i, const HString& s);

    int indexOf(const char* s) const ;
    int indexOf(const HString& s) const ;
    HString& remove(int i,int len);
    HString& remove(const char* s);
    HString& remove(const HString& s);
    HString& replace(const char* t, const char* s);
    HString& replace(const HString& t, const char* s);
    HString& replace(const char* t, const HString& s);
    HString& replace(const HString& t, const HString& s);
    HString sub(int i,int len) const ;

    HString& trim();
};
}

#endif //HSTRING_H
