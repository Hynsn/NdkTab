package com.dp.factory

abstract class Car(){
    abstract fun build()
}

class ChangCheng(): Car(){
    override fun build() {
        println("build changcheng")
    }
}

class ChangAn(): Car(){
    override fun build() {
        println("build changan")
    }
}

class SimpleCarFactory{
    fun create(type: String): Car{
        return when(type){
            "changcheng" -> ChangCheng()
            "changan" -> ChangAn()
            else -> ChangAn()
        }
    }
}

fun main() {
    val factory = SimpleCarFactory().create("changcheng")
    factory.build()
}
