package com.dp.sockstate

import java.net.Socket

class Socket : Socket() {
    private var state: SocketState? = null

    init {
        state = IdleState(this)
    }

    fun connect(addr: String, port: Int) {
        state = ConnectedState(this)
        state?.connect(addr, port)
    }

    fun sendMessage(str: String) {
        state = SendState(this)
        state?.sendMessage(str)
    }

    fun disconnect(){
        state?.sendMessage("disconnect")
        state = DisconnectState(this)
        state?.disconnect()
    }
}