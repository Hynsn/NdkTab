package com.dp.visitor

interface Visitor {
    fun visit(wine: Wine): Float
    fun visit(pig: Pig): Float
    fun visit(television: Television): Float
}