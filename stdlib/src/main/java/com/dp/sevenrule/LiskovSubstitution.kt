package com.dp.sevenrule

open class Calculator {
    open fun calculate(n1: Int, n2: Int): Int {
        return n1 + n2
    }
}

class SuperCalculator : Calculator() {
    override fun calculate(n1: Int, n2: Int): Int {
        return n1 - n2
    }

    fun subtract(n1: Int, n2: Int): Int {
        return n1 - n2
    }
}

abstract class Calculator1 {
    abstract fun stringToList(s: String): ArrayList<String>
}

class SuperCalculator1 : Calculator1() {
    // 这样写编译器会报错
    /*override fun stringToList(s: String): List<String> {
        return listOf()
    }*/
    override fun stringToList(s: String): ArrayList<String> {
        return arrayListOf()
    }
}

object StringProcessor {
    fun stringToList(c: Calculator1, s: String): ArrayList<String> {
        return c.stringToList(s)
    }
}


fun main() {
    // 1
    val c1 = Calculator()
    val s1 = SuperCalculator()
    val sum = s1.calculate(10, 5)
    println("sum $sum")

    // 3
    StringProcessor.stringToList(SuperCalculator1(), "test")
    // 4
    val c2 = Calculator()
    val c3 = SuperCalculator()
    val x = 1
    val y = 2
    val addRet = c2.calculate(x, y)
    println("addRet $addRet")

    val subRet = c3.subtract(x, y)
    println("addRet $subRet")
}