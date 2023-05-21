package com.dp.interpret

class AndExpression(val left: Expression, val right: Expression) : Expression {

    override fun interpret(str: String): Boolean {
        val arry = str.split(SPLIT)
        return left.interpret(arry[0]) && right.interpret(arry[1])
    }

    companion object {
        const val SPLIT = "的"
    }
}