package com.dp.composite

/**
 * 组合设计模式
 */
class CompositeDepartment : Organ {
    val list = ArrayList<Organ>()

    fun add(organ: Organ) {
        list.add(organ)
    }

    override fun personCount(): Int {
        var sum = 0
        list.forEach {
            sum += it.personCount()
        }
        return sum
    }
}

fun main() {
    val compDepart = CompositeDepartment()
    compDepart.add(LeafDepartment1())
    compDepart.add(LeafDepartment2())

    println("personCount: ${compDepart.personCount()}")
}