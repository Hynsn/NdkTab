#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"
#include <android/log.h>

extern const char * LOG_TGA;;

namespace HynLib {

template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
    };
    // 匿名类，避免构造函数泛型T的创建
    mutable struct : public Object{
        char reserved[sizeof(T)]; //mutable get() const 取头结点的值编译器认为会修改头节点的值
        Node* next;
    } m_header;

    int m_length;
    int m_step;
    Node* m_current;

    virtual Node* create(){
        return new Node();
    }
    virtual void destroy(Node* pt){
        delete pt;
    }

public:
    LinkList()
    {
        m_header.next = nullptr;
        m_length = 0;
    }

    Node* position(int i) const
    {
        //reinterpret_cast 处理无关类型之间的转换
        Node* ret = reinterpret_cast<Node*>(&m_header); // current指向头结点
        for (int p=0; p<i; p++) { // 移动到插入的节点
            ret = ret->next;
        }
        return ret;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    bool insert(int i, const T& e)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            Node* node = create();
            if(node!=nullptr){
                Node* current = position(i);

                node->value = e; // 赋值
                node->next = current->next; // node的next指针指向下一个节点
                current->next = node; // 当前节点的next指针指向node

                m_length++;
            }
            else {
                THROW_EXCEPTION(NoEnoughMemoryException,"No memory to insert new element...");
            }
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            Node* current = position(i);

            Node* toDel = current->next;
            if(m_current == toDel) m_current = toDel->next;
            current->next = toDel->next;
            m_length--;
            //delete toDel;
            destroy(toDel);
        }
        return ret;
    }

    virtual T get(int i) const
    {
        T ret;

        if(get(i,ret)){
            return ret;
        }
        else{
            THROW_EXCEPTION(IndexOutofBoundsException,"Invalid parameter i ...");
        }

        return ret;
    }

    bool get(int i, T& e) const
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            e = position(i)->next->value;
        }
        return ret;
    }

    bool set(int i, const T& e)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            position(i)->next->value = e;
        }
        return ret;
    }
    int find(const T& e) const
    {
        int ret = -1;
        int i = 0;
        Node* node = m_header.next;

        while (node){
            if(node->value == e){
                ret = i;
                break;
            }
            else{
                node = node->next;
                i++;
            }
        }
        return ret;
    }

    int length() const
    {
        return m_length;
    }

    void clear()
    {
        while(m_header.next){
            Node* toDel = m_header.next;
            m_header.next = toDel->next;

            m_length--;
            //delete toDel;
            destroy(toDel);
        }
    }

    virtual bool move(int i, int step = 1)
    {
        bool ret = (i>=0) && (i<m_length) && (step>0);
        if(ret){
            m_current = position(i)->next;
            m_step = step;
        }

        return ret;
    }

    virtual bool end()
    {
        return (m_current == nullptr);
    }
    virtual T current()
    {
        if(!end()){
            return m_current->value;
        }
        else{
            THROW_EXCEPTION(InvalidOperationException,"No value at current pos...");
        }
    }

    virtual bool next(){
        int i = 0;
        while (i<m_step && !end()){
            m_current = m_current->next;
            i++;
        }
        return (i == m_step);
    }

    ~LinkList()
    {
        clear();
    }
};
}

#endif // LINKLIST_H
