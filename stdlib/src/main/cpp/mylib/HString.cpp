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

HString::~HString() {
    free(m_str);
}

int HString::length() const {
    return m_length;
}
const char* HString::str() const {
    return m_str;
}

char& HString::operator[](int i) {
    if(i>=0 && i<m_length){
        return m_str[i];
    }
    else {
        THROW_EXCEPTION(IndexOutofBoundsException,"Parameter i is invalid ...");
    }
}

char HString::operator[](int i) const {
    return (const_cast<HString&>(*this))[i]; //const_cast 剔除const属性
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
HString HString::operator-(const char *s) const {
    return HString(*this).remove(s);
}
HString HString::operator-(const HString &s) const {
    return HString(*this).remove(s);
}
HString & HString::operator-=(const char *s) {
    return remove(s);
}
HString & HString::operator-=(const HString &s) {
    return remove(s);
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

bool HString::equal(const char *l, const char *r, int len) const {
    bool ret = true;
    for (int i = 0; i < len && ret; ++i) {
        ret = ret && (l[i]==r[i]);
    }
    return ret;
}

bool HString::startWith(const HString &s) const {
    return startWith(m_str);
}
bool HString::startWith(const char *s) const {
    bool ret = (s != nullptr);
    if(ret){
        int len = strlen(s);
        ret = (len < m_length) && equal(m_str,s,len);
    }
    return ret;
}
bool HString::endWith(const HString &s) const {
    return endWith(m_str);
}
bool HString::endWith(const char *s) const {
    bool ret = (s != nullptr);
    if(ret){
        int len = strlen(s);
        char* str = m_str +(m_length - len);
        ret = (len < m_length) && equal(str,s,len);
    }
    return ret;
}
HString& HString::insert(int i, const char *s) {
    if(i>=0 && i<=m_length){
        if((s != nullptr) && (s[0]!='\0')){
            int len = strlen(s);
            char* str = reinterpret_cast<char*>(malloc(m_length+len+1));
            if(str!= nullptr){
                strncpy(str,m_str,i);
                strncpy(str+i,s,len);
                strncpy(str+i+len,m_str+i,m_length-i);
                str[m_length+len] = '\0';

                free(m_str);
                m_str = str;
                m_length = m_length+len;
            }
            else{
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to add string value...");
            }
        }
    }
    else {
        THROW_EXCEPTION(IndexOutofBoundsException,"Parameter i is invalid ...");
    }
    return (*this);
}

HString& HString::insert(int i, const HString &s) {
    return insert(i,s.m_str);
}
HString& HString::trim() {
    int lt = 0;
    int rt = m_length - 1;
    while (m_str[lt] == ' ') lt++;
    while (m_str[rt] == ' ') rt--;

    if(lt == 0){
        m_str[rt+1] = '\0';
        m_length = rt+1;
    }
    else {
        for (int i=0, j=lt; j <= rt; i++,j++) {
            m_str[i] = m_str[j];
        }
        m_str[rt-lt +1] = '\0';
        m_length = rt-lt +1;
    }

    return (*this);
}

int* HString::make_pmt(const char *p) {
    int len = strlen(p);
    int* ret = static_cast<int*>(malloc(sizeof(int) * len));
    if(ret!=NULL){
        int ll = 0;
        ret[0] = 0;
        for (int i = 1; i < len; ++i) {
            while ((ll>0) && (p[ll]!=p[i])){
                ll = ret[ll-1];
            }

            if(p[ll]==p[i]){ // 扩展
                ll++;
            }
            ret[i] = ll;
        }
    }

    return ret;
}

int HString::kmp(const char *s, const char *p) {
    int ret = -1;
    int s1 = strlen(s);
    int p1 = strlen(p);
    int* pmt = make_pmt(p);

    if((pmt!=NULL) && (p1>0) && (s1>=p1)){
        for (int i=0,j=0; i < s1; i++) {
            // 查表
            while ((j>0) && (s[i]!=p[j])){
                j = pmt[j-1];
            }

            // 正常匹配的情况
            if(s[i]==p[j]){
                j++;
            }
            if(j == p1){
                ret = i+1-p1;
                break;
            }
        }
    }

    free(pmt);

    return ret;
}

int HString::indexOf(const char* s) const {
    return kmp(m_str,s ? s : "");
}
int HString::indexOf(const HString& s) const {
    return kmp(m_str,s.m_str);
}

HString& HString::remove(int i, int len) {
    if((i>0) && (i<m_length)){
        int n = i;
        int m = i+len;
        while ((n<m) && (m<m_length)){
           m_str[n++] = m_str[m++];
        }
        m_str[n] = '\0';
        m_length = n;
    }
    return *this;
}

HString & HString::remove(const char *s) {
    return remove(indexOf(s),s ? strlen(s) : 0);
}

HString & HString::remove(const HString &s) {
    return remove(indexOf(s),s.length());
}

HString & HString::replace(const char *t, const char *s) {
    int index = indexOf(t);
    if(index>0){
        remove(t);
        insert(index,s);
    }
    return *this;
}
HString & HString::replace(const char *t, const HString &s) {
    return replace(t,s.m_str);
}
HString & HString::replace(const HString &t, const char *s) {
    return replace(t.m_str,s);
}
HString & HString::replace(const HString &t, const HString &s) {
    return replace(t.m_str,s.m_str);
}

HString HString::sub(int i, int len) const {
    HString ret;

    if((i>=0) && (i<m_length)){
        // 归一化
        if(len < 0) len = 0;
        if(len+i > m_length) len = m_length-i;

        char* str = reinterpret_cast<char*>(malloc(len+1));
        strncpy(str,m_str+i,len);

        str[len] = '\0';
        ret = str;
    }
    else{
        THROW_EXCEPTION(IndexOutofBoundsException,"Parameter i is invalid ...");
    }
    return ret;
}

}
