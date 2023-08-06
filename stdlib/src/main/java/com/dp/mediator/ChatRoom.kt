package com.dp.mediator

class ChatRoom(val id: Int) {
    private val messages = ArrayList<String>()

    fun enter(user: User) {
        println("${user.name}进入聊天室$id")
    }

    fun operation(user: User, msg: String) {
        val log = "${user.name}说了$msg"
        println(log)
        messages.add(log)
    }

    fun getMessage(): MutableList<String> {
        return messages
    }
}

fun main() {
    val room = ChatRoom(1)
    val user1 = User("张三")
    val user2 = User("李四")
    val user3 = User("王八")
    user1.enter(room)
    user2.enter(room)
    user3.enter(room)
    user1.send("你好")
}