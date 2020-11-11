//
// Created by housaibang on 2020-11-09.
//

#ifndef TREENODE_H
#define TREENODE_H

#include "Object.h"

namespace HynLib{

template <typename T>
class TreeNode : public Object{
public:
    T value;
    TreeNode<T>* parent;
    TreeNode(){
        parent = nullptr;
    }

    virtual ~TreeNode() = 0;
};

template <typename T>
TreeNode<T>::~TreeNode() {

}
}

#endif //TREENODE_H
