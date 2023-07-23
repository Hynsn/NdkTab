package com.dp.observer

interface TextChangedListener {
    fun onChanged(old: String, new: String)
    fun onChanged(old: Int, new: Int, boolean: Boolean)
}