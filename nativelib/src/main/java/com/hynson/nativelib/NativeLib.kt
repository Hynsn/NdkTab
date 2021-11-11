package com.hynson.nativelib

class NativeLib {

    /**
     * A native method that is implemented by the 'nativelib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'nativelib' library on application startup.
        init {
            //System.loadLibrary("nativelib")
            System.loadLibrary("native-lib")
        }
    }

    external fun unbindLogPipe()
    external fun bindLogPipe(): Int
    external fun readMessage(): String?
    external fun writeMessage(msg: String?): Int
    external fun testPipeSize(): Int
}