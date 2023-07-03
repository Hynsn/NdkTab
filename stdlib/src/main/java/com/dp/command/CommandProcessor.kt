package com.dp.command

class CommandProcessor {
    fun handle(className: String, vararg arg: String): Int? {
        try {
            val pkg = this.javaClass.`package`?.name
            val command: Command = Class.forName("$pkg.$className").newInstance() as Command
            return command.execute(*arg)
        } catch (e: Exception) {
            println("未知命令")
            e.printStackTrace()
        }
        return null
    }
}

fun main() {
    val cp = CommandProcessor()
    cp.handle("None", "12")
    cp.handle("Print", "12", "123")
    cp.handle("", "12", "123")
}