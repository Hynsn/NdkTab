package com.ktcode.leet

import kotlin.String

fun main() {

    val str = com.ktcode.leet.String().replaceSpace(StringBuilder("We are Happy"))
    println("replaceSpace == $str")
}

class String {
    fun replaceSpace(oldSb: StringBuilder): String {
        val newSb = StringBuilder()
        oldSb.forEach { c ->
            newSb.append(if(c == ' ') "%20" else c)
        }
        return newSb.toString()
    }
}