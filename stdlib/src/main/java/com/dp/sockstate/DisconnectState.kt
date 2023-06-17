package com.dp.sockstate

import java.net.Socket

class DisconnectState(socket: Socket?) : SocketState(socket) {

    override fun disconnect() {
        socket?.shutdownInput()
        socket?.shutdownOutput()
        socket?.close()
        socket = null
    }
}