package com.dp.templatemethod

abstract class Game {
    protected abstract fun initialize()
    protected abstract fun startPlay()
    protected abstract fun endPlay()

    // 模版
    fun play(){
        initialize()
        startPlay()
        endPlay()
    }
}

fun main() {
    var game:Game = Cricket()
    game.play()
    game = Football()
    game.play()
}