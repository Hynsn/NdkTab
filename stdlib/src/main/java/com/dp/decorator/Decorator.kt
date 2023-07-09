package com.dp.decorator

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override val name: String = "牛奶${coffee.name}"
    override fun cost(): Float {
        return coffee.cost() + 2
    }
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override val name: String = "多糖${coffee.name}"
    override fun cost(): Float {
        return coffee.cost() + 3
    }
}

fun main() {
    val coffee: Coffee = SimpleCoffee()
    val coffeeWithMilk: Coffee = MilkDecorator(coffee)
    val coffeeWithMilkAndSugar: Coffee = SugarDecorator(coffeeWithMilk)
    println("${coffee.name} -> ${coffee.cost()}")
    println("${coffeeWithMilk.name} -> ${coffeeWithMilk.cost()}")
    println("${coffeeWithMilkAndSugar.name} -> ${coffeeWithMilkAndSugar.cost()}")
}