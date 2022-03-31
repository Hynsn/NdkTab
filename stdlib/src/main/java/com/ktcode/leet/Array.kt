package com.ktcode.leet

import kotlin.Array

fun main() {
    val a1: IntArray = intArrayOf(1, 2, 8,9)
    val a2: IntArray = intArrayOf(2, 3, 9,12)
    val a3: IntArray = intArrayOf(4, 7, 10,13)
    val a4: IntArray = intArrayOf(6, 8, 11,15)

    val matrix: Array<IntArray> = arrayOf(a1, a2, a3,a4)

    val array: com.ktcode.leet.Array = Array()
    print("${array.findMatrix(matrix, 3)}")
}

class Array {

    /**
     * 寻找二维数组中是否包含数字x
     * @param 二维数组
     * @return 是否包含
     */
    fun findMatrix(matrix: Array<IntArray>, x: Int): Boolean {
        var ret = false

        val rows = matrix.size
        var row = 0

        var column = matrix[0].size - 1
        while (row < rows && column >= 0) {
            val a = (matrix[row][column]).compareTo(x)
            when {
                a == 0 -> {
                    ret = true
                    break
                }
                a > 0 -> {
                    --column
                }
                else -> {
                    ++row
                }
            }
        }
        return ret
    }
}