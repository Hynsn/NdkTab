package com.dp.proxy

interface PhoneSell {
    fun sell()
}

class MainPhoneSell : PhoneSell {
    override fun sell() {
        println("手机销售")
    }
}