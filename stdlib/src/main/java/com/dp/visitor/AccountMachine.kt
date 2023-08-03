package com.dp.visitor

class AccountMachine {
    private var awt: Float = 0f

    fun getAwt(list: MutableList<Any>): Float {
        val visitor: Visitor = VisitorImpl()
        for (item in list) {
            awt += (item as Goods).accept(visitor)
        }
        return awt
    }
}

fun main() {
    val wine = Wine(10, 5f)
    val pig = Pig(2, 18f)
    val tv = Television(1, 2300f)
    val shoppingList = ShoppingList()
    shoppingList.add(wine)
    shoppingList.add(pig)
    shoppingList.add(tv)
    val accountMachine = AccountMachine()
    val awt = accountMachine.getAwt(shoppingList.list)
    println("总价：$awt")
}