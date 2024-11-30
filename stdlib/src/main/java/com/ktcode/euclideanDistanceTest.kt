package com.ktcode

import kotlin.math.pow
import kotlin.math.sqrt

fun euclideanDistance(vectorA: DoubleArray, vectorB: DoubleArray): Double {
    // 检查向量长度是否相等
    if (vectorA.size != vectorB.size) {
        throw IllegalArgumentException("Vectors must be of the same length.")
    }

    // 计算欧氏距离
    var distance = 0.0
    for (i in vectorA.indices) {
        distance += (vectorA[i] - vectorB[i]).pow(2)
    }
    return sqrt(distance)
}

fun main() {
    // 示例向量
    val vectorA = doubleArrayOf(1.0, 2.0)
    val vectorB = doubleArrayOf(1.0, 2.0)

    // 计算并打印欧氏距离
    val distance = euclideanDistance(vectorA, vectorB)
    println("Euclidean Distance: $distance")
}