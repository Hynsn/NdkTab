package com.dp.flyweight

object ShapeFactory {
    private val circleMap = HashMap<String, Shape>()

    fun getCircle(color: String): Shape {
        var circle = circleMap[color]
        if (circle == null) {
            circle = Circle(color)
            circleMap[color] = circle
            println("cache circle $color-color")
            return circle
        }
        return circle
    }
}

fun main() {
    val colors = arrayListOf("Red", "Green", "Blue", "White", "Black")

    repeat(20) {
        val color = colors[(0..4).random()]
        val circle = ShapeFactory.getCircle(color) as Circle
        circle.apply {
            x = (0..100).random()
            y = (0..100).random()
            radius = 5
        }
        circle.draw()
    }
}