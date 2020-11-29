//
// Created by GeekHou on 2020/11/29.
//

#ifndef BTREE_H
#define BTREE_H
#include "Tree.h"
#include "GTreeNode.h"
#include "Exception.h"
#include "BTreeNode.h"

namespace HynLib{
template <typename T>
class BTree: public Tree<T>{
protected:
    virtual BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const {
        BTreeNode<T>* ret = nullptr;
        if(node!= nullptr){
            if(node->value == value){
                return node;
            }
            else{
                if(ret== nullptr) ret = find(node->left,value);
                if(ret== nullptr) ret = find(node->right,value);
            }
        }
        return ret;
    }
    virtual BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* obj) const {
        BTreeNode<T>* ret = nullptr;
        if(node!= nullptr){
            if(node == obj){
                return node;
            }
            else{
                if(ret== nullptr) ret = find(node->left,obj);
                if(ret== nullptr) ret = find(node->right,obj);
            }
        }
        return ret;
    }
    virtual bool insert(BTreeNode<T>* n,BTreeNode<T>* np,BTNodePos pos){
        bool ret = true;
        if(pos==ANY){
            if(np->left== nullptr) np->left = n;
            else if(np->right== nullptr) np->right = n;
            else ret = false;
        }
        else if(pos==LEFT){
            if(np->left== nullptr) np->left = n;
            else ret = false;
        }
        else if(pos==RIGHT){
            if(np->right== nullptr) np->right = n;
            else ret = false;
        }
        else{
            ret = false;
        }

        return ret;
    }
public:
    bool insert(TreeNode<T>* node) {
        return insert(node,ANY);
    }
    virtual bool insert(TreeNode<T>* node,BTNodePos pos) {
        bool ret = true;
        if( node != NULL ) {
            if( this->m_root == NULL ) {
                node->parent = NULL;
                this->m_root = node;
            }
            else {
                BTreeNode<T>* np = find(node->parent);
                if( np != NULL ) insert(dynamic_cast<BTreeNode<T>*>(node), np, pos);
                else THROW_EXCEPTION(InvalidParameterException, "Invalid parent tree node ...");
            }
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "Parameter node can not be NULL");
        }
        return ret;
    }
    bool insert(const T& value,TreeNode<T>* parent) {
        return insert(value,parent,ANY);
    };
    virtual bool insert(const T& value,TreeNode<T>* parent,BTNodePos pos) {
        bool ret = true;
        BTreeNode<T>* node = BTreeNode<T>::NewNode();
        if( node == NULL )
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create new node ...");
        }
        else
        {
            node->value = value;
            node->parent = parent;

            ret = insert(node, pos);
            if( !ret ) delete node;
        }
        return ret;
    };
    SharePointer< Tree<T> > remove(TreeNode<T>* node) {
        return nullptr;
    }
    SharePointer< Tree<T> > remove(const T& value) {
        return nullptr;
    }
    BTreeNode<T>* find(TreeNode<T>* node) const {
        return find(root(), dynamic_cast<BTreeNode<T>*>(node));
    }
    BTreeNode<T>* find(const T& value) const {
        return find(root(),value);
    }
    BTreeNode<T>* root() const {
        return dynamic_cast<BTreeNode<T>*>(this->m_root);
    }
    int degree() const {
        return 0;
    }
    int count() const {
        return 0;
    }
    int height() const {
        return 0;
    }
    void clear() {
        this->m_root = nullptr;
    }
    ~BTree(){
        clear();
    }
};
}
#endif //BTREE_H
