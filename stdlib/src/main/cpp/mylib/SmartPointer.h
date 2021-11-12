#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Pointer.h"

namespace HynLib {

template<typename T>
class SmartPointer : public Pointer<T>
{
public:
    SmartPointer(T* p = nullptr) : Pointer<T>(p){

    }
    // 拷贝构造函数
    SmartPointer(const SmartPointer<T>& obj){
        this->m_pointer = obj.m_pointer;
        // const_cast去除对象的const属性
        const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
    }
    // 重载赋值操作符
    SmartPointer<T>& operator = (const SmartPointer<T>& obj){
        if(this!=&obj){
            T* p = this->m_pointer;
            this->m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
            delete p;
        }
        return *this; //意义在于支持连续的赋值
    }

    ~SmartPointer()
    {
        delete this->m_pointer;
    }
};

}

#endif // SMARTPOINTER_H
