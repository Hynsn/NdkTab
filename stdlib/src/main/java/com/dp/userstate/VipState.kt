package com.dp.userstate

class VipState(user: User) :UserState(user) {
    override fun play4k() {
        println("Vip播放4k视频")
    }

    override fun play720P() {
        println("Vip播放720P视频")
    }

    override fun play1080P() {
        println("Vip播放1080P视频")
    }
}