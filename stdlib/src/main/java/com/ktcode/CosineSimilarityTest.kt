package com.ktcode

import kotlin.math.sqrt

fun cosineSimilarity(vectorA: DoubleArray, vectorB: DoubleArray): Double {
    // 检查向量长度是否相等
    if (vectorA.size != vectorB.size) {
        throw IllegalArgumentException("Vectors must be of the same length.")
    }

    // 计算点积
    var dotProduct = 0.0
    for (i in vectorA.indices) {
        dotProduct += vectorA[i] * vectorB[i]
    }

    // 计算向量的模
    val magnitudeA = sqrt(vectorA.map { it * it }.sum())
    val magnitudeB = sqrt(vectorB.map { it * it }.sum())

    // 计算余弦相似度
    return dotProduct / (magnitudeA * magnitudeB)
}

fun main() {
    // 示例向量
    val vectorA = doubleArrayOf(1.0, 2.0, 3.0)
    val vectorB = doubleArrayOf(2.0, 4.0, 6.0)

    // 计算并打印余弦相似度
    val similarity = cosineSimilarity(vectorA, vectorB)
    println("Cosine Similarity: $similarity")
}