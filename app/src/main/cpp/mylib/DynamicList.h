#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.h"
#include "Exception.h"

namespace HynLib {
template<typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;
public:
    DynamicList(int capacity){
        this->m_array = new T[capacity];
        if(this->m_array!=nullptr){
            this->m_capacity = capacity;
            this->m_length = 0;
        }
        else {
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create DynamicList ...");
        }
    }
    int capacity() const{
        return m_capacity;
    }

    // 重新设置顺序存储空间大小
    void resize(int capacity){
        if(capacity != m_capacity){
            T* array = new T[capacity];
            if(array!=nullptr){
                // 保存当前array中的数据
                int length = (this->m_length<capacity?this->m_length:capacity);
                for (int i=0;i<length;i++) {
                    array[i] = this->m_array[i];
                }
                // 更新释放array
                T* temp = this->m_array;

                this->m_capacity = capacity;
                this->m_array = array;
                this->m_length = length;

                delete[] temp;
            }
            else {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to reszie DynamicList ...");
            }
        }
    }
    ~DynamicList(){
        delete[] this->m_array;
    }
};

}

#endif // DYNAMICLIST_H
