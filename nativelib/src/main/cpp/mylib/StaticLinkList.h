#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#include "LinkList.h"

namespace HynLib {
template<typename T, int N>
class StaticLinkList : public LinkList<T> {
protected:
    typedef typename LinkList<T>::Node Node;

    struct SNode : Node{
        void* operator new(size_t size, void* ps){
            (void)size;
            return ps;
        }
    };

    unsigned char m_space[sizeof(SNode) * N];
    int m_used[N];

    Node *create() {
        SNode* ret = NULL;
        for (int i = 0; i < N; i++) {
            if(!m_used[i]){
                ret = reinterpret_cast<SNode*>(m_space)+i; // 分配内存
                ret = new(ret) SNode();    // 调用构造函数
                m_used[i] = 1;
                break;
            }
        }
        return ret;
    }

    void destroy(Node* pn) {
        SNode* space = reinterpret_cast<SNode*>(m_space);
        SNode* psn = dynamic_cast<SNode*>(pn); // 从父类指针转换到子类指针
        for (int i = 0; i < N; i++) {
            if(psn == (space+i)){
                m_used[i] = 0;
                psn->~SNode();
                break;
            }
        }
    }

public:
    StaticLinkList(){
        for (int i = 0; i < N; i++) {
            m_used[i] = 0;
        }
    }
    int capacity(){
        return N;
    }
    ~StaticLinkList(){
        this->clear();
    }
};
}
#endif // STATICLINKLIST_H