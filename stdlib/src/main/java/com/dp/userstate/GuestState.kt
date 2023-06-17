package com.dp.userstate

class GuestState(user: User) : UserState(user) {
    override fun play4k() {
        throw RuntimeException("游客禁止播放4k视频")
    }

    override fun play720P() {
        println("正在播放720P视频")
    }

    override fun play1080P() {
        throw RuntimeException("游客禁止播放1080视频")
    }
}