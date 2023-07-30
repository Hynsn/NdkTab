package com.dp.facade

class SmartSceneFacade {
    private val lights = arrayListOf<Light>(Light("客厅"), Light("卧室"))
    private val tv = TV()

    private val airConditioner = AirConditioner()


    fun goHome() {
        println("回家场景：")
        lights[0].turnOn()
        airConditioner.open()
    }

    fun goToWork() {
        println("去上班：")
        for (light in lights) {
            light.turnOff()
        }
        tv.power(false)
        airConditioner.close()
    }

    fun nightSleep() {
        println("要睡觉了：")
        for (light in lights) {
            light.turnOff()
        }
        tv.power(false)
        airConditioner.sleep()
    }
}

fun main() {
    val smartSceneFacade = SmartSceneFacade()
    smartSceneFacade.goToWork()
    smartSceneFacade.goHome()
    smartSceneFacade.nightSleep()
}