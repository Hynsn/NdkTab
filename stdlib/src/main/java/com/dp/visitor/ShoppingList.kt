package com.dp.visitor

class ShoppingList {
    val list = ArrayList<Any>()
    fun add(any: Any) {
        list.add(any)
    }

    fun remove(any: Any) {
        list.remove(any)
    }
}