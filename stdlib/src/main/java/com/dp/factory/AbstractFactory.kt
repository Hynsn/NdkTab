package com.dp.factory

abstract class SuvCar(){
    abstract fun build()
}

interface CarFactory1 {
    fun createCar(): Car
    fun createSuvCar():SuvCar
}


class SmartFactory : CarFactory1 {
    override fun createCar(): Car {
        return ChangCheng()
    }

    override fun createSuvCar(): SuvCar {
        return SuvCar1()
    }
}

class Store1(val factory: CarFactory1) {
}

fun main() {

    val store = Store1(SmartFactory())
    store.factory.createCar().build()
    store.factory.createSuvCar().build()
}
