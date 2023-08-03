package com.dp.visitor

interface Goods {
    fun accept(visitor: Visitor): Float
    fun account(): Float
}

/**
 * 酒类
 */
data class Wine(
    val count: Int,
    val price: Float
) : Goods {
    override fun accept(visitor: Visitor): Float {
        return visitor.visit(this)
    }

    override fun account(): Float {
        println("酒按瓶计价，购买数量为：${count}瓶，单价为$price")
        return count * price
    }
}

/**
 * 猪肉
 */
data class Pig(
    val count: Int,
    val price: Float
) : Goods {
    override fun accept(visitor: Visitor): Float {
        return visitor.visit(this)
    }

    override fun account(): Float {
        println("猪肉按斤计价，购买数量为：${count}斤，单价为$price")
        return count * price
    }
}

/**
 * 电视
 */
data class Television(
    val count: Int,
    val price: Float
) : Goods {
    override fun accept(visitor: Visitor): Float {
        return visitor.visit(this)
    }

    override fun account(): Float {
        println("电视按件台价，购买数量为：${count}台，单价为$price")
        return count * price
    }
}