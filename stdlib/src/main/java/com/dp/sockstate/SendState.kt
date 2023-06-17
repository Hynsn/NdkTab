package com.dp.sockstate

import java.net.Socket

class SendState(socket: Socket?) : SocketState(socket) {
    override fun sendMessage(str: String) {
        socket?.getOutputStream()?.write(str.toByteArray(Charsets.UTF_8))
        println("发送了$str $socket")
    }
}