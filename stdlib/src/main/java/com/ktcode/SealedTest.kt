package com.ktcode

sealed class Kpi {
    object A : Kpi()
    object B : Kpi()
    object C : Kpi()
    data class D(val name: String) : Kpi()
}

class Group(private val kip: Kpi) {
    fun show() = when (kip) {
        is Kpi.A -> "优秀"
        is Kpi.B -> "良好"
        is Kpi.C -> "一般"
        is Kpi.D -> "很差,${kip.name}"
    }
}

fun main() {
    val g = Group(Kpi.D("小明"))
    println(g.show())
}