package com.ktcode.leet

import java.lang.StringBuilder
import java.util.*

fun main() {
    val list:LinkedList = LinkedList()
    list.add(e = 1)
    list.add(e = 2)
    list.add(e = 3)
    list.add(e = 4)
    list.print()
    list.revers1(list.headNode)


    list.remove(3)
    list.print()

    list.revers1(list.headNode)

    list.clear()
    list.add(e = 1)
    list.add(e = 2)
    list.add(e = 3)
    list.add(e = 4)
    list.print()

    list.revers1(list.headNode)
}

class Node {
    var value: Int = -1
    var pNext: Node? = null
}

class LinkedList {
    val headNode: Node = Node()
    var length:Int = 0

    init {

        println("LinkedList init")
    }

    private fun position(p:Int) : Node? {
        var curNode: Node? = headNode
        for (i in 1..p){
            curNode = curNode?.pNext
        }
        return curNode
    }

    // 添加
    fun add(i: Int? = null,e: Int){
        val node = Node()
        val j = i ?: length
        val posNode = position(j)

        posNode?.run {
            node.value = e // 赋值
            node.pNext = pNext // 待插入节点的next指针指向插入位置节点的next指针
            pNext = node // 插入位置节点指向插入节点
            length++
        }
    }

    // 删除
    fun remove(i: Int): Boolean{
        val ret = i in 0 until length

        if(ret){
            val curNode = position(i)
            curNode?.run {
                val toDel = pNext
                pNext = toDel?.pNext
                toDel?.pNext = null
                length--
            }
        }

        return ret
    }

    // 清除
    fun clear(){
        while (headNode.pNext!=null){
            val toDel = headNode.pNext
            toDel?.run {
                headNode.pNext = pNext
                pNext = null
                length--
            }
        }
    }

    // 打印链表

    fun print(){
        val sb = StringBuilder()
        var curNode: Node? = headNode
//        sb.append(headNode.value)
        while(curNode != null){
            if(curNode != headNode){
                sb.append(" ${curNode.value}")
            }
            curNode = curNode.pNext
        }
        println("LinkedList length $length :$sb")
    }

    // 反转打印 递归实现
    fun revers1(node: Node?) {
        node?.let {
            it.pNext?.let { next ->
                revers1(next.pNext)
            }
            print("${it.value}")
        }
        /*if(curNode != null){
            if(curNode.pNext != null){
                revers()
            }
            print("- ${curNode.value}")
        }*/
    }
    // stack实现
    fun revers2(){

    }
}