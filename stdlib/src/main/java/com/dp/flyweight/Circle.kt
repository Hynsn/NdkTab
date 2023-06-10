package com.dp.flyweight

class Circle(var color: String? = null) : Shape {
    var x: Int = -1
    var y: Int = -1
    var radius: Int = 0
    override fun draw() {
        println("hash=${hashCode()}:draw(color=$color,x=$x,y=$y,r=$radius)")
    }
}