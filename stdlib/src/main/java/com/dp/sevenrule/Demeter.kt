package com.dp.sevenrule

/**
 * 卡
 */
class Card(var balance: Int = 10)

/**
 * 顾客
 */
class Customer(
    val card: Card = Card()
)

/**
 * 店铺
 */
class SurfShop {
    fun chargeCustomer(c: Customer, f: Int) {
        c.card.balance -= f
    }
}

class Customer1(val card: Card1 = Card1()) {
    fun pay(f: Int) {
        card.deduct(f)
    }
}

class Card1(var balance: Int = 10) {
    fun deduct(f: Int) {
        balance -= f
    }
}

class SurfShop1 {
    fun chargeCustomer(c: Customer1, f: Int) {
        c.pay(f)
    }
}

fun main() {
    val s = SurfShop()
    val c = Customer()
    s.chargeCustomer(c, 10)
    println("finish: ${c.card.balance}")

    val s1 = SurfShop1()
    val c1 = Customer1()
    s1.chargeCustomer(c1, 10)
    println("finish: ${c1.card.balance}")
}
