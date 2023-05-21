package com.dp.interpret

class TerminalExpression(data: Array<String>) : Expression {
    private val set = HashSet<String>()

    init {
        for (s in data) {
            set.add(s)
        }
    }

    override fun interpret(str: String): Boolean {
        return set.contains(str)
    }
}