#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.h"
#include "Exception.h"

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
    Node m_header;
    int m_length;
public:
    LinkList()
    {
        m_header.next = nullptr;
        m_length = 0;
    }

    bool insert(const T& e)
    {
        return insert(m_length,m_header);
    }
    bool insert(int i, const T& e)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            Node* node = new Node();
            if(node!=nullptr){
                Node* current = &m_header;
                for (int p=0;p<i;p++) { // 移动到插入的节点
                    current = current->next;
                }

                node->value = e;
                node->next = current->next;
                current->next = node;

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
            Node* current = &m_header;
            for (int p=0;p<i;p++) { // 移动到插入的节点
                current = current->next;
            }

            Node* toDel = current->next;
            current->next = toDel->next;
            delete toDel;

            m_length--;
        }
        return ret;
    }
    bool get(int i, T& e)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            Node* current = &m_header;
            for (int p=0;p<i;p++) { // 移动到插入的节点
                current = current->next;
            }
            e = current->next->value;
        }
        return ret;
    }
    bool set(int i, const T& e)
    {
        bool ret = ((i>=0)&&(i<=m_length));
        if(ret){
            Node* current = &m_header;
            for (int p=0;p<i;p++) { // 移动到插入的节点
                current = current->next;
            }
            current->next->value = e;
        }
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

            delete toDel;
        }
        m_length = 0;
    }
    ~LinkList()
    {
        clear();
    }
};
}

#endif // LINKLIST_H
