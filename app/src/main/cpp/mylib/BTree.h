//
// Created by GeekHou on 2020/11/29.
//

#ifndef BTREE_H
#define BTREE_H
#include "Tree.h"
#include "Exception.h"
#include "BTreeNode.h"
#include "LinkQueue.h"

namespace HynLib{
enum BTTraversal
{
    PreOrder,
    InOrder,
    PostOrder,
    LevelOrder
};
template <typename T>
class BTree: public Tree<T>{
protected:
    LinkQueue<BTreeNode<T>*> m_queue;
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
    void remove(BTreeNode<T>* node,BTree<T>*& ret){
        ret = new BTree<T>();

        if(ret != nullptr){
            if(root() != node){
                BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
                if(parent->left==node) parent->left = nullptr;
                else if(parent->right==node) parent->right = nullptr;
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
    virtual void free(BTreeNode<T>* node){
        if(node!= nullptr){
            free(node->left);
            free(node->right);
            if(node->flag()) delete node;
        }
    }
    int count(BTreeNode<T>* node) const{
        return ((node != nullptr) ? (count(node->left) + count(node->right) + 1) : 0);
    }
    int height(BTreeNode<T>* node) const{
        int ret = 0;
        if(node != nullptr){
            int lh = height(node->left);
            int rh = height(node->right);

            ret = ((lh > rh) ? lh : rh) + 1;
        }
        return ret;
    }
    int degree(BTreeNode<T>* node) const
    {
        int ret = 0;

        if( node != NULL )
        {
            // 非常精妙的改写，由下往上改写；
            BTreeNode<T>* child[] = { node->left, node->right};
            ret = (!!node->left + !!node->right);  // 结点数的度

            for(int i=0; (i<2) && (ret<2); i++)  //保证结点度数达到要求后，直接不求
            {
                int d = degree(child[i]);

                if( ret < d )
                {
                    ret = d;
                }
            }
        }
        return ret;
    }
    void PreOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != nullptr )
        {
            queue.add(node);
            PreOrderTraversal(node->left, queue);
            PreOrderTraversal(node->right, queue);
        }
    }
    void inOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != nullptr )
        {
            inOrderTraversal(node->left, queue);
            queue.add(node);
            inOrderTraversal(node->right, queue);
        }
    }
    void postOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
    {
        if( node != nullptr )
        {
            postOrderTraversal(node->left, queue);
            postOrderTraversal(node->right, queue);
            queue.add(node);
        }
    }
    void traversal(BTTraversal order, LinkQueue<BTreeNode<T>*>& queue)
    {
        switch(order)
        {
            case PreOrder:
                PreOrderTraversal(root(), queue);
                break;
            case InOrder:
                inOrderTraversal(root(), queue);
                break;
            case PostOrder:
                postOrderTraversal(root(), queue);
                break;
            default:
                THROW_EXCEPTION(InvalidParameterException, "Parameter order is invalid ...");
                break;
        }
    }
    BTreeNode<T>* connect(LinkQueue<BTreeNode<T>*>& queue) {
        BTreeNode<T>* ret = nullptr;
        if(queue.length() > 0 ){
            // init
            ret = queue.front();
            BTreeNode<T>* slider = queue.front();
            queue.remove();
            slider->left = nullptr;
            // connect
            while (queue.length() > 0){
                slider->right = queue.front();
                queue.front()->left = slider;
                slider = queue.front();
                queue.remove();
            }
            slider->right = nullptr;
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
    }
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
    }
    SharePointer<Tree<T>> remove(TreeNode<T>* node) {
        BTree<T>* ret = nullptr;
        node = find(node);
        if(node == nullptr){
            THROW_EXCEPTION(InvalidParameterException, "Parameter node is invalid ...");
        }
        else{
            remove(dynamic_cast<BTreeNode<T>*>(node),ret);
            m_queue.clear();
        }
        return ret;
    }
    SharePointer<Tree<T>> remove(const T& value) {
        BTree<T>* ret = nullptr;
        BTreeNode<T>* node = find(value);
        if(node == nullptr){
            THROW_EXCEPTION(InvalidParameterException, "Cant find the tree node via value ...");
        }
        else{
            remove(node,ret);
            m_queue.clear();
        }
        return ret;
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
        m_queue.clear();
        this->m_root = nullptr;
    }
    bool begin() {
        bool ret = (root() != NULL);
        if(ret){
            m_queue.clear();
            m_queue.add(root());
        }
        return ret;
    }
    bool end() {
        return (m_queue.length() == 0);
    }
    bool next() {
        bool ret = (m_queue.length() > 0);
        if(ret){
            BTreeNode<T>* node = m_queue.front();
            m_queue.remove();
            if(node->left != NULL){
                m_queue.add(node->left);
            }
            if(node->right != NULL){
                m_queue.add(node->right);
            }
        }
        return ret;
    }
    T current()
    {
        if(!end()) {
            return m_queue.front()->value;
        }
        else {
            THROW_EXCEPTION(InvalidOperationException, "No value at current position ...");
        }
    }
    SharePointer<Array<T>> traversal(BTTraversal order)
    {
        DynamicArray<T>* ret = nullptr;
        LinkQueue<BTreeNode<T>*> queue;
        traversal(order, queue);
        ret = new DynamicArray<T>(queue.length());
        if( ret != nullptr ) {
            for(int i=0; i < ret->length(); i++, queue.remove()) {
                ret->set(i, queue.front()->value);
            }
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "No memory to create return array ...");
        }
        return  ret;
    }

    BTreeNode<T>* thread(BTTraversal order){
        BTreeNode<T>* ret = nullptr;
        LinkQueue<BTreeNode<T>*> queue;
        traversal(order, queue);
        ret = connect(queue);

        this->m_root = nullptr;
        m_queue.clear();

        return ret;
    }


    ~BTree(){
        clear();
    }
};
}
#endif //BTREE_H
