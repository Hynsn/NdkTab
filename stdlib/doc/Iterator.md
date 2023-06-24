### 概念
提供一种遍历集合元素的方法，而不暴露集合内部的实现。

#### 角色介绍

- iterator 迭代器接口: 定义访问和遍历集合元素的接口，一般包含next和hasNext方法。
- concrete iterator 具体迭代器: 实现迭代器接口，迭代器的核心逻辑实现。
- aggregate 集合接口: 定义创建迭代器的接口方法，内部定义了iterator方法
- concrete aggregate 具体集合接口: 实现集合接口，创建具体的iterator角色。

#### UML

![](./img/iterator_pattern.png)

### 代码实现
kt中两种方式实现迭代器。
实现Iterator接口，它是一次性不可逆的。
```kt
data class Book(val name: String)

class BookList(val books: List<Book>) : Iterator<Book> {
    private val iterator: Iterator<Book> = books.iterator()

    override fun hasNext() = iterator.hasNext()

    override fun next() = iterator.next()
}

fun main() {
    val bookList = BookList(listOf(Book("Kotlin核心编程"), Book("深入理解Java虚拟机")))
    for (book in bookList) {
        println("for in -> ${book.name}")
    }
    bookList.forEach { book -> println("for each -> ${book.name}") }
}
```
输出：
>for in -> Kotlin核心编程
for in -> 深入理解Java虚拟机

实现Iterable接口，它每次都会获取一个新的迭代器
```kt
class BookList(val books: List<Book>) : Iterable<Book> {
    override fun iterator(): Iterator<Book> = books.iterator()
}
```
输出：
>for in -> Kotlin核心编程
for in -> 深入理解Java虚拟机
for each -> Kotlin核心编程
for each -> 深入理解Java虚拟机
### 优缺点

优点
- 抽象性
- 简化客户端代码
- 支持多种集合类型
- 解耦

缺点
- 代码变复杂
- 性能开销

### 应用场景
用于提供一致的遍历接口，遍历不同类型的集合。
列举应用场景
1. 数据库查询结果
2. 文件系统目标
3. 社交网络中的消息列表

#### 迭代器在源码中的应用
Iterator源码
```kt
/**
 * An iterator over a collection or another entity that can be represented as a sequence of elements.
 * Allows to sequentially access the elements.
 */
public interface Iterator<out T> {
    /**
     * Returns the next element in the iteration.
     */
    public operator fun next(): T

    /**
     * Returns `true` if the iteration has more elements.
     */
    public operator fun hasNext(): Boolean
}
```
Iterable源码
```kt
/**
 * Classes that inherit from this interface can be represented as a sequence of elements that can
 * be iterated over.
 * @param T the type of element being iterated over. The iterator is covariant in its element type.
 */
public interface Iterable<out T> {
    /**
     * Returns an iterator over the elements of this object.
     */
    public operator fun iterator(): Iterator<T>
}
```
### 总结
迭代器增加新的遍历方式时便于解耦。官方源码ArrayList、LinkedList、TreeSet等集合对象都使用了该模式。在kt中我们还可以iterator()运算符来实现迭代器，但重载运算符后会导致forEach无法使用。 因为forEach是Iterator和Iterable的扩展函数。
