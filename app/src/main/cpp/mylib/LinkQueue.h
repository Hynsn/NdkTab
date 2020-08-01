#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Queue.h"
#include "LinkList.h"
#include "Exception.h"


namespace HynLib{
    template<typename T>
    class LinkQueue : public Queue<T>{
    protected:
        LinkList<T> m_list;
    public:
        LinkQueue(){

        }
        void add(const T& e){
            m_list.insert(e); // 队尾入队
        }
        void remove(){
            if(m_list.length() > 0){
                m_list.remove(0); // 队头出队
            }
            else{
                THROW_EXCEPTION(InvalidParameterException,"No element int current queue...");
            }
        }
        T front() const {
            if(m_list.length() > 0){
                return m_list.get(0);
            }
            else{
                THROW_EXCEPTION(InvalidParameterException,"No element int current queue...");
            }
        }
        void clear(){
            m_list.clear();
        }
        int length() const {
            return m_list.length();
        }
    };
}

#endif //LINKQUEUE_H
