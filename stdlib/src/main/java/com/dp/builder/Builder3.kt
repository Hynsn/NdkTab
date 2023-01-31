package com.dp.builder

import androidx.annotation.StringRes

class Dialog1 {
    var title: String = ""
    var content: String = ""

    // 内敛函数结合lambda
    inline fun show(func: Dialog1.() -> Unit) {
        this.func()
        this.show()
    }

    fun show() {
        println("title:$title,content:$content")
    }
}

class Dialog2 {
    var title: String = ""
    var content: String = ""

    fun title(@StringRes res: Int? = null, text: CharSequence? = null): Dialog2 {
        text?.let {
            title = it.toString()
        }
        return this
    }

    fun content(@StringRes res: Int? = null, text: CharSequence? = null): Dialog2 {
        text?.let {
            content = it.toString()
        }
        return this
    }

    inline fun show(func: Dialog2.() -> Unit) {
        this.func()
        this.show()
    }

    fun show() {
        println("title:$title,content:$content")
    }
}

class Dialog private constructor(
    val title: String,
    val text: String?,
    val onAccept: (() -> Unit)?
) {
    class Builder(val title: String) {
        var text: String? = null
        var onAccept: (() -> Unit)? = null
        fun setText(text: String?): Builder {
            this.text = text
            return this
        }

        fun setOnAccept(onAccept: (() -> Unit)?): Builder {
            this.onAccept = onAccept
            return this
        }

        fun build() = Dialog(title, text, onAccept)
    }
}

fun main() {
    Dialog1().show {
        title = "标题"
        content = "内容"
    }

    Dialog2().show {
        title(text = "标题")
        content(text = "内容")
    }

    val dialog1 = Dialog.Builder("Some title")
        .setText("Great dialog")
        .setOnAccept { println("I was clicked") }
        .build()
    val dialog2 = Dialog.Builder("Another dialog")
        .setText("I have no buttons")
        .build()
    val dialog3 = Dialog.Builder("Dialog with just a title").build()
}