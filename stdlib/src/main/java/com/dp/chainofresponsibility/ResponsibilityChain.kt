package com.dp.chainofresponsibility

/*
声明类对象时需要接受两个构造参数，其中 definetAt 为校验函数， f 为处理函数
当 PartialFunction 类对象执行 invoke 方法时，definetAt 会输入参数 p1 进行有效校验
如果校验结果通过，则执行 f 函数，同时将 p1 作为参数传毒给它，反之抛出异常
 */
class PartialFunction<in P1, out R>(
    private val definetAt: (P1) -> Boolean,
    private val f: (P1) -> R
) : (P1) -> R {
    override fun invoke(p1: P1): R {
        if (definetAt(p1)) {
            return f(p1)
        } else {
            throw IllegalAccessException()
        }
    }

    fun isDefinedAt(p1: P1) = definetAt(p1)
}

/**
 * orElse 方法种可以传入另一个 PartialFunction 类对象 that，它也就是责任链模式中的后继者
 * infix 关键字让 orElse 成为一个中缀函数，从而让责任链调用的语法变得更加直观
 */
infix fun <P1, R> PartialFunction<P1, R>.orElse(that: PartialFunction<P1, R>): PartialFunction<P1, R> {
    return PartialFunction({
        this.isDefinedAt(it) || that.isDefinedAt(it)
    }) {
        when {
            this.isDefinedAt(it) -> this(it)
            else -> that(it)
        }
    }
}

data class Current(var cash: Int, val message: MutableList<String>)


val RMB_5 = run {
    val definetAt: (Current) -> Boolean = { it.cash >= 5 }
    val handler: (Current) -> Unit = {
        println("处理5元")
        val num = it.cash / 5
        it.cash = it.cash % 5
        it.message.add("5元 * $num")
    }
    PartialFunction(definetAt, handler)
}
val RMB_10 = run {
    val definetAt: (Current) -> Boolean = { it.cash >= 10 }
    val handler: (Current) -> Unit = {
        println("处理10元")
        val num = it.cash / 10
        it.cash = it.cash % 10
        it.message.add("10元 * $num")
    }
    PartialFunction(definetAt, handler)
}
val RMB_20 = run {
    val definetAt: (Current) -> Boolean = { it.cash >= 20 }
    val handler: (Current) -> Unit = {
        println("处理20元")
        val num = it.cash / 20
        it.cash = it.cash % 20
        it.message.add("20元 * $num")
    }
    PartialFunction(definetAt, handler)
}
val RMB_50 = run {
    val definetAt: (Current) -> Boolean = { it.cash >= 50 }
    val handler: (Current) -> Unit = {
        println("处理50元")
        val num = it.cash / 50
        it.cash = it.cash % 50
        it.message.add("50元 * $num")
    }
    PartialFunction(definetAt, handler)
}
val RMB_100 = run {
    val definetAt: (Current) -> Boolean = { it.cash >= 100 }
    val handler: (Current) -> Unit = {
        println("处理100元")
        val num = it.cash / 100
        it.cash = it.cash % 100
        it.message.add("100元 * $num")
    }
    PartialFunction(definetAt, handler)
}

fun ATMMachine(atmChain: PartialFunction<Current, Unit>, cash: Current): Int {
    atmChain(cash)
    return if (cash.cash < 5) {
        if (cash.cash > 0) {
            cash.message.add("1元 * ${cash.cash}")
        }
        0
    } else {
        ATMMachine(atmChain, cash)
    }
}

fun main(args: Array<String>) {
    val atmChain = RMB_100 orElse RMB_50 orElse RMB_20 orElse RMB_10 orElse RMB_5
    val user = Current(1084, ArrayList<String>())
    ATMMachine(atmChain, user)
    for (s in user.message) {
        println(s)
    }
}