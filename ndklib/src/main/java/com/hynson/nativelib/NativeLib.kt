package com.hynson.nativelib

class NativeLib {

    companion object {
        init {
            System.loadLibrary("nativelib")
        }
    }

}