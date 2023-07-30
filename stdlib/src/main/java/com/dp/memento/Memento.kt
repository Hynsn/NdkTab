package com.dp.memento

/**
 * 备忘录
 */
data class Memento(
    val state: String? = null
)

/**
 * 原发器
 */
class Originator {
    var state: String? = null

    fun save(): Memento {
        return Memento(state)
    }

    fun recover(memento: Memento) {
        state = memento.state
    }

}

/**
 * 看管人
 */
class Caretaker {
    private val mementos = ArrayList<Memento>()

    fun addMemento(memento: Memento) {
        mementos.add(memento)
    }

    fun getMemento(i: Int): Memento {
        return mementos[i]
    }
}

fun main() {
    val originator = Originator()
    val caretaker = Caretaker()
    originator.state = "State#1"
    originator.state = "State#2"
    caretaker.addMemento(originator.save())
    originator.state = "State#3"
    caretaker.addMemento(originator.save())
    originator.state = "State#4"

    println("Current State:${originator.state}")
    originator.recover(caretaker.getMemento(0))
    println("0 State:${originator.state}")
    originator.recover(caretaker.getMemento(1))
    println("1 State:${originator.state}")
}