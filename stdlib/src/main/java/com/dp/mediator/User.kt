package com.dp.mediator

interface UserAbs {
    fun enter(chatRoom: ChatRoom)
    fun send(msg: String)
    fun receive()
}

data class User(val name: String) : UserAbs {
    private var room: ChatRoom? = null

    override fun enter(chatRoom: ChatRoom) {
        room = chatRoom
        room?.enter(this)
    }

    override fun send(msg: String) {
        room?.operation(this, msg)
    }

    override fun receive() {
        room?.getMessage()?.forEach {
            println(it)
        }
    }
}
