package com.dp.userstate

class MemberState(user: User) :UserState(user) {
    override fun play4k() {
        throw RuntimeException("会员禁止播放4k视频")
    }

    override fun play720P() {
        println("正在播放720P视频")
    }

    override fun play1080P() {
        println("正在播放1080视频")
    }
}