package com.dp.templatemethod

/**
 * 板球游戏
 */
class Cricket : Game() {
    override fun initialize() {
        println("Cricket initialize")
    }

    override fun startPlay() {
        println("Cricket startPlay")
    }

    override fun endPlay() {
        println("Cricket endPlay")
    }
}