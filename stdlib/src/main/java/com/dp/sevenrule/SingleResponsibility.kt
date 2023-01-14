package com.dp.sevenrule

interface LaptopFunction {
    fun startUp()
    fun shutDown()
}
interface LaptopProperty {
    val cpu:String
    val size:Int
    // 新增分辨率
    val resolution:String
}

class MacLaptopFunction : LaptopFunction {
    override fun startUp() {
        println("开机")
    }

    override fun shutDown() {
        println("关机")
    }
}

class MacLaptopProperty: LaptopProperty {
    override val cpu: String = "M1"
    override val size: Int = 1
    override val resolution: String = "1080*960"
    override fun toString(): String {
        return "com.dp.sevenrule.MacLaptopProperty(cpu='$cpu', size=$size, resolution='$resolution')"
    }

}

data class MacBook(
    val property: MacLaptopProperty,
    val function: MacLaptopFunction
)

fun main(){
    val mac = MacBook(MacLaptopProperty(), MacLaptopFunction())
    mac.run {
        println(property.toString())
        function.startUp()
        function.shutDown()
    }
}