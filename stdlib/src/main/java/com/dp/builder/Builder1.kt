package com.dp.builder

class Computer(
    val mainboard: String, // 主板
    val cpu: String, // 处理器
    val ram: String, // 内存
    val battery: String, // 电源
    val gpu: String? = null, // 显卡
    val hardDisk: String? = null, // 硬盘
    val networkInterface: String? = null, // 网线接口
    val cdDriver: String? = null, // 光驱
    val os: String? = null, // 系统
    val chassis: String? = null, // 机箱
    val mouse: String? = null, // 鼠标
    val keyboard: String? = null, // 键盘
    val monitor: String? = null // 显示器
)

class Car {
    // 作用域函数指定
    var color: String = ""
    var doors: Int = 0
    var wheel: String = ""
    override fun toString(): String {
        return "Car(color='$color', doors=$doors, wheel='$wheel')"
    }
}

fun main() {
    // 具名参数
    val computer = Computer(
        "超微X8QB6-F", "Intel Xeon E7-8870", "海盗船(CORSAIR) 复仇者LPX DDR4 2133 64GB 7000", "西门子豪华供电柜",
        gpu = "Leadtek/丽台Quadro Plex 7000",
        os = "Windows 11",
        mouse = "RAPOO雷柏 3710 2.4G激光无线鼠标",
        keyboard = "Optimus Maximus 多功能 概念式键盘",
        monitor = "Sharp/夏普 LB-1085 108英寸 FULL HD专业液晶显示器"
    )
    val car = Car().apply {
        color = "Red"
        doors = 4
        wheel = "Good"
    }
    println(car)
}