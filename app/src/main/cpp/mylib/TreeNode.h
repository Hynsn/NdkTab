//
// Created by housaibang on 2020-11-09.
//

#ifndef TREENODE_H
#define TREENODE_H

#include "Object.h"

namespace HynLib{

template <typename T>
class TreeNode : public Object{
protected:
    bool m_flag;
    void* operator new (size_t size) throw(){
        return Object::operator new(size);
    }
public:
    T value;
    TreeNode<T>* parent;
    TreeNode(){
        parent = nullptr;
        m_flag = false;
    }
    bool flag(){
        return m_flag;
    }
    virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::~TreeNode() {

}
}

#endif //TREENODE_H
