package com.dp.sevenrule

interface NotificationService{
    fun sendNotification(info:String)
}

class EmailService : NotificationService{
    override fun sendNotification(info: String) {
        println("Email发送：$info")
    }
}
class MessageService : NotificationService{
    override fun sendNotification(info: String) {
        println("Message发送：$info")
    }
}

class WXService : NotificationService{
    override fun sendNotification(info: String) {
        println("wx发送：$info")
    }
}

class NotificationService2{
    fun sendNotification(ns:NotificationService,info: String){
        ns.sendNotification(info)
    }
}

fun main() {
    val service = NotificationService2()
    service.sendNotification(MessageService(),"1")
    service.sendNotification(EmailService(),"2")
    service.sendNotification(WXService(),"3")

}
