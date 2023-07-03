package com.dp.command

interface Command {
    fun execute(vararg arg: String):Int
}