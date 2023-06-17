package com.dp.sockstate

import java.net.Socket

abstract class SocketState(var socket: Socket?) {

    open fun connect(addr: String, port: Int) {
        println("开始连接...")
    }

    open fun sendMessage(str: String) {
        if (socket == null || !(socket!!.isConnected)) {
            println("未连接还不能发送！")
        }
    }

    open fun disconnect() {

    }
}