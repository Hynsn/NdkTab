package com.dp.factory



interface CarFactory {
    fun createCar(): Car
}

class SuvCar1 : SuvCar(){
    override fun build() {
        println("build SuvCar1")
    }

}

class ChangChengFactory : CarFactory {
    override fun createCar(): Car {
        return ChangCheng()
    }

}

class ChangAnFactory : CarFactory {
    override fun createCar(): Car {
        return ChangAn()
    }
}

class Store(val factory: CarFactory) {
    fun create(): Car {
        return factory.createCar()
    }
}

fun main() {
    // 长安工厂生产汽车
    val store = Store(ChangAnFactory())
    store.create().build()

    // 长城工厂生产汽车
    val store1 = Store(ChangChengFactory())
    store1.create().build()
}