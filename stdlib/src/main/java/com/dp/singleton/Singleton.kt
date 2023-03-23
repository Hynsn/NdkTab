package com.dp.singleton

object SingletonHungry {

    fun test() {
        println("SingletonHungry")
    }
}

class SingletonLazy {
    companion object {
        private var instance: SingletonLazy? = null
        fun getInstance(): SingletonLazy? {
            if (instance == null) {
                instance = SingletonLazy()
            }
            return instance
        }
        // 也可以这样写
        /*val instance by lazy(LazyThreadSafetyMode.NONE) {
            SingletonDCL()
        }*/
    }

    fun test() {
        println("SingletonLazy")
    }
}

class SingletonSafeLazy(t: Int) {
    companion object {
        private var sInstance: SingletonSafeLazy? = null

        @Synchronized
        fun getInstance(t: Int): SingletonSafeLazy? {
            if (sInstance == null) {
                sInstance = SingletonSafeLazy(t)
            }
            return sInstance
        }
    }

    fun test() {
        println("SingletonSafeLazy")
    }
}

class SingletonDCL {
    companion object {
        val instance by lazy(LazyThreadSafetyMode.SYNCHRONIZED) {
            SingletonDCL()
        }
    }

    fun test() {
        println("SingletonDCL")
    }
}

class SingletonStatic {
    companion object {
        fun getInstance() = Holder.instance
    }

    private object Holder {
        val instance = SingletonStatic()
    }

    fun test() {
        println("SingletonStatic")
    }
}

fun main() {
    SingletonHungry.test()

    SingletonLazy.getInstance()?.test()

    SingletonSafeLazy.getInstance(1)?.test()

    SingletonDCL.instance.test()

    SingletonStatic.getInstance().test()
}