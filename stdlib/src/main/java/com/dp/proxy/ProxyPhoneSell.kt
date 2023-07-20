package com.dp.proxy

import java.lang.reflect.Proxy

class ProxyPhoneSell : PhoneSell {
    private val mainPhoneSell = MainPhoneSell()
    override fun sell() {
        println("赚取200元服务费")
        mainPhoneSell.sell()
    }
}


class ProxyFactory {
    private val phoneSell = MainPhoneSell()
    fun getProxy() = Proxy.newProxyInstance(
        phoneSell.javaClass.classLoader,
        phoneSell.javaClass.interfaces
    ) { proxy, method, args ->
        println("收取200元服务费")
        method.invoke(phoneSell, *args.orEmpty())
    } as PhoneSell
}

fun main() {
    ProxyPhoneSell().sell()
    ProxyFactory().getProxy().sell()
}