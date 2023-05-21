package com.dp.interpret

/**
 * 抽象表达式
 */
interface Expression {
    fun interpret(str: String): Boolean
}
