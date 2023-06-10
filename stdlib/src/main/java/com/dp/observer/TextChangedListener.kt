package com.dp.observer

interface TextChangedListener {
    fun onChanged(old: String, new: String)
}