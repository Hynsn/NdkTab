package com.dp.sockstate

object TcpClient {


//    private var state: SocketState? = null
//    private var socket: Socket? = null
//
//    init {
//        socket = Socket()
//        state = IdleState(socket)
//        state = ConnectedState(socket)
//    }
//
//
//

}

fun main() {
    val client = Socket()
    client.connect("192.168.8.206", 8080)
    repeat(10){
        client.sendMessage("发送数据")
    }
    Thread.sleep(1000)
    client.disconnect()
}