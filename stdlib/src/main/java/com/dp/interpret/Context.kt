package com.dp.interpret

class Context {
    private val citys = arrayOf("北京", "太原")
    private val persons = arrayOf("老人", "孕妇")

    private val expression: Expression

    init {
        expression = AndExpression(TerminalExpression(citys), TerminalExpression(persons))
    }

    fun freeRide(info: String) {
        //提示语，可自行设置
        val s1 = "哔！" + info.split(AndExpression.SPLIT)[1] + "卡，欢迎乘车，您本次乘车免费！"
        val s2 = "哔！欢迎乘车，您本次乘车扣费2元！"
        println(if (expression.interpret(info)) s1 else s2)
    }
}

fun main() {
    val bus = Context()
    bus.freeRide("北京的老人")
    bus.freeRide("太原的孕妇")
    bus.freeRide("太原的儿童")
    bus.freeRide("上海的老人")
}