package com.dp.visitor

class VisitorImpl : Visitor {
    override fun visit(wine: Wine): Float {
        return wine.account()
    }

    override fun visit(pig: Pig): Float {
        return pig.account()
    }

    override fun visit(television: Television): Float {
        return television.account()
    }
}