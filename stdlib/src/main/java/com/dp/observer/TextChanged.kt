package com.dp.observer

class TextChanged : TextChangedListener {
    override fun onChanged(old: String, new: String) {
        println("onChanged: $old -->  $new")
    }
}