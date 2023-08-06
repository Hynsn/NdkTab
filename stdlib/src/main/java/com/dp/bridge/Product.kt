package com.dp.bridge


abstract class Product(payment: Payment) {
    abstract fun purchase()
}

/**
 * 图书
 */
class Book(private val payment: Payment) : Product(payment) {
    override fun purchase() {
        payment.processPayment()
        println("Purchase book")
    }
}

/**
 * 电子书
 */
class Electronics(private val payment: Payment) : Product(payment) {
    override fun purchase() {
        payment.processPayment()
        println("Purchase electronics")
    }
}
