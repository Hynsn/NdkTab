package com.dp.templatemethod

/**
 * 足球游戏
 */
class Football : Game() {
    override fun initialize() {
        println("Football initialize")
    }

    override fun startPlay() {
        println("Football startPlay")
    }

    override fun endPlay() {
        println("Football endPlay")
    }
}