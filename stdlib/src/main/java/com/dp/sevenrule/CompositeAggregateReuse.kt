package com.dp.sevenrule

/**
 * 汽油车
 */
open class GasolineCar {
    open fun move() {
        println("GasolineCar move")
    }
}

/**
 * 电动车
 */
class ElectricCar {
    fun move() {
        println("ElectricCar move")
    }
}

class RedGasolineCar : GasolineCar() {
    override fun move() {
        println("RedGasolineCar move")
    }
}

class BlueGasolineCar : GasolineCar() {
    override fun move() {
        println("BlueGasolineCar move")
    }
}


interface Energy {

}

class Gasoline : Energy {
    override fun toString(): String {
        return "Gasoline()"
    }
}

class Electric : Energy {
    override fun toString(): String {
        return "Gasoline()"
    }
}

interface Color {

}

class Bule : Color {
    override fun toString(): String {
        return "Bule()"
    }
}

class Red : Color {
    override fun toString(): String {
        return "Red()"
    }
}

class Car(val energy: Energy, val color: Color) {
    fun move() {
        println("$energy $color move")
    }
}

fun main() {
    val r1 = RedGasolineCar()
    r1.move()

    val c = Car(Gasoline(), Bule())
    c.move()
}
