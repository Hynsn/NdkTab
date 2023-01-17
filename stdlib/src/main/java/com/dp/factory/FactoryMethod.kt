package com.dp.factory


interface CarsFactory {
    fun createCar(): Car
}

class ChangChengFactory : CarsFactory {
    override fun createCar(): Car {
        return ChangCheng1()
    }
}

class ChangCheng1() : Car() {
    override fun build() {
        println("build changcheng")
    }
}

class ChangAnFactory : CarsFactory {
    override fun createCar(): Car {
        return ChangAn1()
    }
}

class ChangAn1() : Car() {
    override fun build() {
        println("build changan")
    }
}

class Store(val factory: CarsFactory) {
    fun create(): Car {
        return factory.createCar()
    }
}

fun main() {
    val store = Store(ChangAnFactory())
    store.create().build()
}