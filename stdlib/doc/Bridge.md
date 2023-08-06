### 概念

抽象和现实之间搭建桥梁，分离实现和抽象。

#### 角色介绍

- Abstraction：抽象 定义抽象接口，通常包含对实现接口的引用。 
- Refined Abstraction：扩展抽象，对抽象的扩展，可以是抽象类的子类或具体实现类。 
- Implementor：实现，定义实现接口，提供基本操作的接口。 
- Concrete Implementor：具体实现，实现实现接口的具体类。

#### UML

一张图片

抽象（What）
用户可见
产品
定义数据类型的类。
实现（How）
系统正常工作的底层代码
付款方式
处理数据存储和检索的类
### 代码实现

```kt
abstract class Product(payment: Payment) {
    abstract fun purchase()
}

/**
 * 图书
 */
class Book(private val payment: Payment) : Product(payment) {
    override fun purchase() {
        payment.processPayment()
        println("Purchase book")
    }
}

/**
 * 电子书
 */
class Electronics(private val payment: Payment) : Product(payment) {
    override fun purchase() {
        payment.processPayment()
        println("Purchase electronics")
    }
}
interface Payment {
    fun processPayment()
}
/**
 * 信用卡支付
 */
class CreditCartPayment() : Payment {
    override fun processPayment() {
        println("Processing credit card payment")
    }
}

/**
 * 微信支付
 */
class WeCharPayment() : Payment {
    override fun processPayment() {
        println("Processing wechat payment")
    }
}

/**
 * 新增现金支付
 */
class CashPayment() : Payment {
    override fun processPayment() {
        println("Processing cash payment")
    }
}

fun main() {
    val creditCart: Payment = CreditCartPayment()
    val wechat: Payment = WeCharPayment()
    val cash: Payment = CashPayment()

    val electronics = Electronics(creditCart)
    electronics.purchase()
    val book = Book(wechat)
    book.purchase()
    val book1 = Book(cash)
    book1.purchase()
}
```

### 优缺点

优点
- 让抽象和实现独立
- 灵活和扩展的架构
- 增加代码复用性，可读性和可维护性
- 简化测试和调试

缺点
- 增加复杂度
- 更多的规划和设计工作
- 不必要的抽象和冗余代码
- 可读性降低

### 应用场景

隐藏实现细节，避免抽象和实现的绑定（运行时切换实现和动态配置），提高代码可扩展性。
- GUI框架，用户界面和实现分离
- 绘图程序，形状、颜色线条分离以支持不同的组合。
- 数据库驱动系统，数据api和增删查改分离支持不同的数据库。

### 总结

和适配器模式区别
是一种架构设计，适用于前期设计，而适配器模式。
适配器是基于已有代码出现了不兼容，将不兼容的接口连接起来。
参考：

- a

- b

- c
