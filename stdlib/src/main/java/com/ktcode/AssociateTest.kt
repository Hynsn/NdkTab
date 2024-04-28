package com.ktcode

/**
 * Author: Hynsonhou
 * Date: 2024/4/28 15:36
 * Description: AssociateTest
 * History:
 * <author> <time> <version> <desc>
 * Hynsonhou 2024/4/28 1.0 首次创建
 */

// 假设有一个Person类
data class Person(val name: String, val age: Int)

fun main() {
    // 使用associate将每个Person的name作为键，age作为值转换为Map
    val people = listOf(Person("Alice", 30), Person("Bob", 25), Person("Charlie", 32))
    val nameToAgeMap = people.associate { it.name to it.age }
    println(nameToAgeMap)
    // 使用associateBy将每个Person的age作为键，整个Person作为值转换为Map
    val ageToPersonMap = people.associateBy { it.age }
    println(ageToPersonMap)
    // 使用associateWith将每个Person的name作为键，将name的长度作为值转换为Map
    val nameToLengthMap = people.associateWith { it.name.length }
    println(nameToLengthMap)
}

