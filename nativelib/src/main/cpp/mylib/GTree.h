//
// Created by housaibang on 2020-11-09.
//

#ifndef GTREE_H
#define GTREE_H

#include "Tree.h"
#include "GTreeNode.h"
#include "Exception.h"

namespace HynLib{
template <typename T>
class GTree: public Tree<T>{
protected:
    LinkQueue<GTreeNode<T>*> m_queue;

    GTreeNode<T>* find(GTreeNode<T>* node, const T& value) const {
        GTreeNode<T>* ret = nullptr;
        if(node!= nullptr){
            if(node->value == value){
                return node;
            }
            else{
                for(node->child.move(0);!node->child.end() && (ret== nullptr) ; node->child.next()){
                    ret = find(node->child.current(),value);
                }
            }
        }

        return ret;
    }
    GTreeNode<T>* find(GTreeNode<T>* node, GTreeNode<T>* obj) const {
        GTreeNode<T>* ret = nullptr;
        if(node!= nullptr){
            if(node == obj){
                return node;
            }
            else{
                for (node->child.move(0);
                     !node->child.end() && (ret == nullptr); node->child.next()) {
                    ret = find(node->child.current(), obj);
                }
            }
        }
        return ret;
    }
    void free(GTreeNode<T>* node){
        if(node!= nullptr){
            for (node->child.move(0);!node->child.end(); node->child.next()) {
                free(node->child.current());
            }
            if(node->flag())
                delete node;
        }
    }

    void remove(GTreeNode<T>* node,GTree<T>*& ret){
        ret = new GTree<T>();

        if(ret != nullptr){
            if(root() != node){
                // 父节点的子节点的链表指针
                LinkList<GTreeNode<T>*>& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child;
                child.remove(child.find(node));
                node->parent = nullptr;
            }
            else{
                this->m_root = nullptr;
            }
            ret->m_root = node;
        }
        else{
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create tree ...");
        }
    }
    int count(GTreeNode<T>* node) const {
        int ret = 0;
        if(node != nullptr){
            ret = 1;

            for (node->child.move(0);!node->child.end(); node->child.next()) {
                ret += count(node->child.current());
            }
        }
        return ret;
    }
    int height(GTreeNode<T>* node) const {
        int ret = 0;
        if(node != nullptr){
            for (node->child.move(0);!node->child.end(); node->child.next()) {
                int h = height(node->child.current());
                if(h > ret){
                    ret = h;
                }
            }
            ret += 1;
        }
        return ret;
    }
    int degree(GTreeNode<T>* node) const {
        int ret = 0;
        if(node != nullptr){
            ret = node->child.length();
            for (node->child.move(0);!node->child.end(); node->child.next()) {
                int h = degree(node->child.current());
                if(h > ret){
                    ret = h;
                }
            }
        }
        return ret;
    }
public:
    GTree(){}
    bool insert(TreeNode<T>* node){
        bool ret = true;
        if(node!= nullptr){
            if(this->m_root!= nullptr){
                GTreeNode<T>* np = find(node->parent);
                if(np!= nullptr){
                    GTreeNode<T>* n = dynamic_cast<GTreeNode<T>*>(node);
                    if(np->child.find(n) < 0)
                        np->child.insert(n);
                }
                else{
                    THROW_EXCEPTION(InvalidOperationException,"Invalid parent node ...");
                }
            }
            else{
                node->parent = nullptr;
                this->m_root = node;
            }
        }
        else{
            THROW_EXCEPTION(InvalidParameterException,"Parameter node cannot be null ...");
        }
        return ret;
    }

    bool insert(const T& value,TreeNode<T>* parent){
        bool ret = true;

        GTreeNode<T>* node = GTreeNode<T>::NewNode();
        if(node!= nullptr){
            node->value = value;
            node->parent = parent;

            insert(node);
        }
        else{
            THROW_EXCEPTION(NoEnoughMemoryException,"No memory to create tree node ...");
        }

        return ret;
    }

    // 设计为智能指针返回，由调用者释放
    SharePointer< Tree<T> > remove(TreeNode<T>* node) {
        GTree<T>* ret = nullptr;
        node = find(node);
        if(node!= nullptr){
            remove(dynamic_cast<GTreeNode<T>*>(node),ret);
            m_queue.clear();
        }
        else{
            THROW_EXCEPTION(InvalidParameterException,"Parameter node is invalid ...");
        }
        return ret;
    }

    SharePointer< Tree<T> > remove(const T& value) {
        GTree<T>* ret = nullptr;
        GTreeNode<T>* node = find(value);
        if(node!= nullptr){
            remove(node,ret);
            m_queue.clear();
        }
        else{
            THROW_EXCEPTION(InvalidParameterException,"Can not find the node parameter value ...");
        }
        return ret;
    }
    GTreeNode<T>* find(TreeNode<T>* node) const {
        return find(root(), dynamic_cast<GTreeNode<T>*>(node));
    }
    GTreeNode<T>* find(const T& value) const {
        return find(root(),value);
    }
    GTreeNode<T>* root() const {
        return dynamic_cast<GTreeNode<T>*>(this->m_root);
    }

    bool begin(){
        bool ret = (root()!= nullptr);
        if(ret){
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }

    bool end(){
        return (m_queue.length()==0);
    }
    T current(){
        if(!end()){
            return m_queue.front()->value;
        }
        else{
            THROW_EXCEPTION(InvalidOperationException, "No value at current position...");
        }
    }

    bool next(){
        bool ret = (m_queue.length() > 0);

        if(ret){
            GTreeNode<T>* node = m_queue.front();
            m_queue.remove();// 出队
            for (node->child.move(0);!node->child.end(); node->child.next()) {
                m_queue.add(node->child.current());
            }
        }

        return ret;
    }

    int degree() const {
        return degree(root());
    }
    int count() const {
        return count(root());
    }
    int height() const {
        return height(root());
    }
    void clear() {
        free(root());
        this->m_root = nullptr;
        m_queue.clear();
    }


    ~GTree(){
        clear();
    }
};
}

#endif //GTREE_H
