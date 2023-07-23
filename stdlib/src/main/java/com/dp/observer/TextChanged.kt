package com.dp.observer

class TextChanged : TextChangedListener {
    override fun onChanged(old: String, new: String) {
        println("onChanged: $old -->  $new")
    }

    override fun onChanged(old: Int, new: Int, boolean: Boolean) {
        println("onChanged: $boolean $old -->  $new")
    }
}