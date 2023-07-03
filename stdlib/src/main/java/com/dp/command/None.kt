package com.dp.command

class None : Command {
    override fun execute(vararg arg: String): Int {
        println("None:${arg.toList()}")
        return 1
    }
}