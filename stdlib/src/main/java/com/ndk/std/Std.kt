package com.ndk.std

class Std {

    /**
     * A native method that is implemented by the 'nativelib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        init {
            System.loadLibrary("nativelib")
        }
    }

    external fun unbindLogPipe()
    external fun bindLogPipe(): Int
    external fun readMessage(): String?
    external fun writeMessage(msg: String?): Int
    external fun testPipeSize(): Int
}