package com.dp.iterator

data class Book(val name: String)

//class BookList(val books: List<Book>) : Iterator<Book> {
//    private val iterator: Iterator<Book> = books.iterator()
//
//    override fun hasNext() = iterator.hasNext()
//
//    override fun next() = iterator.next()
//}

class BookList(val books: List<Book>) : Iterable<Book> {
    override fun iterator(): Iterator<Book> = books.iterator()
}
//class BookList(val books: List<Book>) {
//    operator fun iterator(): Iterator<Book> = books.iterator()
//}
fun main() {
    // 使用
    val bookList = BookList(listOf(Book("Kotlin核心编程"), Book("深入理解Java虚拟机")))
    for (book in bookList) {
        println("for in -> ${book.name}")
    }
    bookList.forEach { book -> println("for each -> ${book.name}") }
}
