package com.dp.bridge

interface Payment {
    fun processPayment()
}

/**
 * 信用卡支付
 */
class CreditCartPayment() : Payment {
    override fun processPayment() {
        println("Processing credit card payment")
    }

}

/**
 * 微信支付
 */
class WeCharPayment() : Payment {
    override fun processPayment() {
        println("Processing wechat payment")
    }
}

/**
 * 新增现金支付
 */
class CashPayment() : Payment {
    override fun processPayment() {
        println("Processing cash payment")
    }
}

fun main() {
    val creditCart: Payment = CreditCartPayment()
    val wechat: Payment = WeCharPayment()
    val cash: Payment = CashPayment()

    val electronics = Electronics(creditCart)
    electronics.purchase()
    val book = Book(wechat)
    book.purchase()
    val book1 = Book(cash)
    book1.purchase()
}