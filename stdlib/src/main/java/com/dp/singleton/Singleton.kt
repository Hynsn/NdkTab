package com.dp.singleton

object SingletonA{

    fun test(){
        println("SingletonA")
    }
}

class SingletonB1{
    companion object{
        val instance by lazy(LazyThreadSafetyMode.NONE) {
            SingletonB1()
        }
    }

    fun test(){
        println("SingletonB")
    }
}

class SingletonB2(t: Int) {
    companion object{
        private var sInstance: SingletonB2? = null

        @Synchronized
        fun getInstance(t:Int): SingletonB2? {
            if (sInstance == null) {
                sInstance = SingletonB2(t)
            }
            return sInstance
        }
    }

    fun test(){
        println("SingletonB")
    }
}

class SingletonC{
    companion object{
        val instance by lazy(LazyThreadSafetyMode.SYNCHRONIZED) {
            SingletonB1()
        }
    }

    fun test(){
        println("SingletonB")
    }
}

class SingletonD{

    companion object{
        fun getInstance() = Holder.instance
    }

    private object Holder{
        val instance = SingletonD()
    }

    fun test(){
        println("SingletonB")
    }
}

fun main() {
    SingletonA.test()

    SingletonB1.instance.test()


    SingletonB2.getInstance(1)?.test()

    SingletonC.instance.test()

    SingletonD.getInstance().test()
}