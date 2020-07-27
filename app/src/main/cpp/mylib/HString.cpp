#include <string>
#include <cstdlib>

#include "HString.h"
#include "Exception.h"

using namespace std;

namespace HynLib{

void HString::init(const char *s) {
    m_str = strdup(s);
    if(m_str){
        m_length = strlen(m_str);
    }
    else{
        THROW_EXCEPTION(NoEnoughMemoryException,"No memory to strdup String...");
    }
}

HString::HString() {
    init("");
}
HString::HString(char c) {
    char s[] = {c,'\0'};
    init(s);
}
HString::HString(const char *c) {
    init(c ? c : "");
}
HString::HString(const HString &s) {
    init(s.m_str);
}

int HString::length() const {
    return m_length;
}
const char* HString::str() const {
    return m_str;
}

HString::~HString() {
    free(m_str);
}

bool HString::operator==(const HString &s) const {
    return (strcmp(m_str,s.m_str) == 0);
}
bool HString::operator==(const char* s) const {
    return (strcmp(m_str,s ? s : "") == 0);
}
bool HString::operator!=(const HString &s) const {
    return !(*this == s);
}
bool HString::operator!=(const char* s) const {
    return !(*this == s);
}
bool HString::operator>(const HString &s) const {
    return (strcmp(m_str,s.m_str) > 0);
}
bool HString::operator > (const char* s)  {
    return (strcmp(m_str,s ? s : "") > 0);
}
bool HString::operator<(const HString &s) const {
    return (strcmp(m_str,s.m_str) < 0);
}
bool HString::operator<(const char* s) const {
    return (strcmp(m_str,s ? s : "") < 0);
}
bool HString::operator>=(const HString &s) const {
    return (strcmp(m_str,s.m_str) >= 0);
}
bool HString::operator>=(const char* s) const {
    return (strcmp(m_str,s ? s : "") >= 0);
}
bool HString::operator<=(const HString &s) const {
    return (strcmp(m_str,s.m_str) <= 0);
}
bool HString::operator <= (const char* s) const {
    return (strcmp(m_str,s ? s : "") <= 0);
}
HString HString::operator + (const HString &s) const{
    return (*this + s.m_str);
}
HString HString::operator + (const char* s) const{
    HString ret;
    int len = (m_length + strlen(s ? s :""));
    char* str = reinterpret_cast<char*>(malloc(len+1));
    if(str){
        strcpy(str,m_str);
        strcat(str,s ? s : "");

        free(ret.m_str);

        ret.m_str = str;
        ret.m_length = len;

        return ret;
    }
    else{
        THROW_EXCEPTION(NoEnoughMemoryException,"No memory to add String...");
    }
}
HString& HString::operator+=(const HString &s) {
    return (*this = *this + s);
}
HString& HString::operator+=(const char *s) {
    return (*this = *this + s);
}
HString& HString::operator = (const HString& s){
    return (*this = s.m_str);
}
HString& HString::operator = (const char* s) {
    if(m_str!=s){
        char* str = strdup(s ? s : "");
        if(str){
            free(m_str);

            m_str = str;
            m_length = strlen(m_str);
        }
        else{
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to assign new String...");
        }
    }
    return *this;
}
HString& HString::operator = (const char c) {
    char s[] = {c,'\0'};
    return (*this = s);
}

}
