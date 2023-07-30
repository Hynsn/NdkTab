package com.dp.facade

class Light(val name: String) {
    fun turnOn() {
        println("${name}灯打开")
    }

    fun turnOff() {
        println("${name}灯关闭")
    }
}

class TV {
    fun power(boolean: Boolean) {
        println("电视电源${boolean}")
    }
}

class AirConditioner {
    fun open() {
        println("空调打开")
    }

    fun sleep() {
        println("空调睡眠")
    }

    fun close() {
        println("空调关闭")
    }
}
