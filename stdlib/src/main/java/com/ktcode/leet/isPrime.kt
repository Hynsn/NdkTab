package com.ktcode.leet


fun isPrime(range: IntRange) {
    // 2~ 100
    for (i in range) {
        var isPrime = true
        for (j in 2..(i / 2)) {
            if ((i % j) == 0) {
                isPrime = false
                break
            }
        }
        if (isPrime) {
            print("$i ")
        }
    }
}

fun main() {
    isPrime(2..100)
}