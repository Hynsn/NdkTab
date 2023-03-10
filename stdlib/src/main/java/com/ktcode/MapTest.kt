package com.ktcode

data class Crash(
    val path:String,
    var distance:Float // 相似度
)

data class Record(
    val name:String,
    val path:String,
)

fun main() {

    val map = LinkedHashMap<String,MutableList<Crash>>()
    map["a"] = mutableListOf()

    val test = arrayListOf<Record>(Record("a","test"),Record("b","test"),Record("c","test"),Record("a","test"))
    for (s in test) {
        val info = map[s.name]
        info?.run {
            val distance = (0..10).random().toFloat()
            info.add(Crash(s.path,distance))
        }
    }

    for (entry in map) {
        println(entry.value)
    }
}