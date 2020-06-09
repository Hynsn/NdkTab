#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.h"

namespace HynLib {

template <typename T>
class DynamicArray : public Array<T>
{
protected:
    int m_length;
    // 优化代码
    T* copy(T* array,int len,int newLen){
        T* ret = new T[newLen];
        if(ret!=nullptr){
            int size = (len<newLen)?len:newLen;
            for (int i=0;i<size;i++) {
                ret[i] = array[i];
            }
        }
        return ret;
    }
    void update(T* array,int length){
        if(array!=nullptr){
            T* temp = this->m_array;

            this->m_array = array;
            this->m_length = length;

            delete [] temp;
        }
        else {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to update DynamicArray ...");
        }
    }
    void init(T* array,int length){
        if(array!=nullptr){
            this->m_array = array;
            this->m_length = length;
        }
        else {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to init DynamicArray ...");
        }
    }
public:
    DynamicArray(int length){
        init(new T[length],length); // 优化代码
        /*
        this->m_array = new T[length];
        if(this->m_array!=nullptr){
            this->m_length = length;
        }
        else {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray ...");
        }
        */
    }
    // 拷贝构造函数
    DynamicArray(const DynamicArray<T>& obj){
        init(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length); // 优化代码
        /*
        this->m_array = new T[obj.m_length];
        if(this->m_array!=nullptr){
            this->m_length = obj.m_length;

            for (int i=0;i<obj.m_length;i++) {
                this->m_array[i] = obj.m_array[i];
            }
        }
        else {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicArray ...");
        }
        */
    }
    // 赋值操作符
    DynamicArray<T>& operator = (const DynamicArray<T>& obj){
        if(this!=&obj){
            update(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length); // 优化后
            /*
            T* array = new T[obj.m_length];
            if(array!=nullptr){
                for (int i=0;i<obj.m_length;i++) {
                    array[i] = obj.m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = obj.m_length;

                delete [] temp;
            }
            else {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to copy DynamicArray ...");
            }
            */
        }
        return *this;
    }
    int length() const{
        return m_length;
    }
    void resize(int length){
        if(length!=m_length){
            update(copy(this->m_array,m_length,length),length); // 优化后
            /*
            T* array = new T[length];

            if(array!=nullptr){
                int size = (length<m_length)?length:m_length;
                for (int i=0;i<size;i++) {
                    array[i] = this->m_array[i];
                }
                T* temp = this->m_array;

                this->m_length = length;
                this->m_array = array;

                delete [] temp;
            }
            else {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to resize DynamicArray ...");
            }
            */
        }
    }

    ~DynamicArray(){
        delete [] this->m_array;
    }
};

}

#endif // DYNAMICARRAY_H
