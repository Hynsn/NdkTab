package com.dp.observer

import kotlin.properties.Delegates

class TextView {
    var listener: TextChangedListener? = null
    // 可观察者属性，接收两个参数 初始值；修改处理器handler,handler会在每次赋值时调用，接收三个参数：当前属性声明，旧值，新值
    // Delegates.vetoable 可对属性赋值进行拦截，返回false即为拦截
    var text: String by Delegates.observable("init") { _, oldValue, newValue ->
        listener?.onChanged(oldValue, newValue)
    }
}

fun main() {

    val textView = TextView().apply {
        listener = TextChanged()
    }
    textView.text = "first"
    textView.text = "second"
}