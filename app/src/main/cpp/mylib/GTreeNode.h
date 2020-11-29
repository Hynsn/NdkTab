//
// Created by housaibang on 2020-11-09.
//

#ifndef GTREENODE_H
#define GTREENODE_H

#include <stddef.h>
#include "TreeNode.h"
#include "LinkList.h"

namespace HynLib{
template <typename T>
class GTreeNode : public TreeNode<T>{

public:
    LinkList<GTreeNode<T>*> child;

    static GTreeNode<T>* NewNode(){
        GTreeNode<T>* ret = new GTreeNode<T>();
        if(ret != nullptr){
            ret->m_flag = true;
        }
        return ret;
    }
};
}

#endif //GTREENODE_H
