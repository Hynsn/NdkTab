package com.dp.builder

class Car1(
    val model: String? = null,
    val year: Int = 0
) {
    private constructor(builder: Builder) : this(
        builder.model,
        builder.year
    )

    class Builder {
        var model: String? = null
        var year: Int = -1

        fun build() = Car1(this)
    }

    companion object {
        /**
         * 带接收者的函数类型,这意味着我们需要向函数传递一个Builder类型的实例
         */
        inline fun build(block: Builder.() -> Unit) = Builder().apply(block).build()
    }

    override fun toString(): String {
        return "Car1(model=$model, year=$year)"
    }
}

fun main() {
    val car2 = Car1.build {
        model = "名字"
        year = 2017
    }
    println(car2)
}