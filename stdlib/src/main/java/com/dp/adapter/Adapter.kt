package com.dp.adapter

interface CTemp {
    fun getCTemp(): Float
}

open class FTemp(
    val temp: Float
)

// 使用继承的方式
class F2CAdapter1(temp: Float) : FTemp(temp), CTemp {
    override fun getCTemp(): Float {
        return (temp - 32) * 5 / 9
    }
}

class F2CAdapter2(val fTemp: FTemp) : CTemp {
    override fun getCTemp(): Float {
        return (fTemp.temp - 32) * 5 / 9
    }

}

fun main() {
    val f = FTemp(100f)
    val adapter1 = F2CAdapter1(f.temp)

    println("类继承 f: ${f.temp},c:${adapter1.getCTemp()}")

    val adapter2 = F2CAdapter2(f)
    println("对象 f: ${f.temp},c:${adapter2.getCTemp()}")

}