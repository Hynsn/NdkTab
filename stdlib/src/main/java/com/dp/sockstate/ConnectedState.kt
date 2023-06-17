package com.dp.sockstate

import java.net.InetSocketAddress
import java.net.Socket

class ConnectedState(socket: Socket?) : SocketState(socket) {
    override fun connect(addr: String, port: Int) {
        super.connect(addr, port)
        val sockAddr = InetSocketAddress(addr, port)
        socket?.connect(sockAddr)
    }

}