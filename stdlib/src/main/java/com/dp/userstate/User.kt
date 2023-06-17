package com.dp.userstate

class User(val name: String){
    private var userState:UserState
    init {
        userState = GuestState(this)
    }

    fun register(){
        userState = MemberState(this)
    }

    fun openVIP(){
        userState = VipState(this)
    }

    fun play4k() {
        userState.play4k()
    }

    fun play720P() {
        userState.play720P()
    }

    fun play1080P() {
        userState.play1080P()
    }
}

fun main() {
    val user = User("张三")
    user.play720P()
//    user.register()
    user.play1080P()
//    user.openVIP()
    user.play4k()
}