package com.dp.decorator

interface Coffee {
    val name: String
    fun cost(): Float
}

class SimpleCoffee : Coffee {
    override val name: String = "咖啡"
    override fun cost(): Float = 6f
}

abstract class CoffeeDecorator(protected val coffee: Coffee) : Coffee by coffee
