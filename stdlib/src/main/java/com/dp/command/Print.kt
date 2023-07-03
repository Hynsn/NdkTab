package com.dp.command

class Print : Command {
    override fun execute(vararg arg: String): Int {
        println("Print:${arg.toList()}")
        return 1
    }
}