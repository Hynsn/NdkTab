package com.ktcode.leet

fun main(){
    val n1 = Node(1)
    val n2 = Node(2)
    val n3 = Node(3)

    n1.next = n2

    n2.next = n3

}

class LinkedList{
    
}
class Node(value: Int) {
    var next: Node? = null
}
