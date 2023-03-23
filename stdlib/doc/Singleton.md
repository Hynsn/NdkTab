### 概念

保证一个类只有一个实例，并为该实例提供一个全局唯一的访问节点。

### 饿汉式

描述：

比较常用，实例在类加载初始化是就创建好。

```kt
object SingletonHungry {
    fun test() {
        println("SingletonHungry")
    }
}
```

**借助object声明，有以下特点**

- 线程安全，使用object声明可直接调用，object声明的类可以具有父类；
- object 类可以包含属性、函数以及init块；
- 不允许有构造函数；
- 不能以类的实例化方式实例化对象；
- 当第一次使用对象提供延迟初始化时，该对象将被实例化；

### 懒汉式

描述：
在用的时候去检查有没有实例，如果没有有则直接返回，没有则新建。在多线程下，if（singleton==null)会产生多个实例，所以线程不安全。

```kt
class SingletonLazy {
    companion object {
        private var instance: SingletonLazy? = null
        fun getInstance(): SingletonLazy? {
            if (instance == null) {
                instance = SingletonLazy()
            }
            return instance
        }
        // 也可以这样写
        /*val instance by lazy(LazyThreadSafetyMode.NONE) {
            SingletonDCL()
        }*/
    }

    fun test() {
        println("SingletonLazy")
    }
}
```

### 线程安全的懒汉式

描述：
有很好的lazyloading效果，多线程安全，但效率很低。该方法使用不太频繁。

```kt
class SingletonSafeLazy(t: Int) {
    companion object {
        private var sInstance: SingletonSafeLazy? = null

        @Synchronized
        fun getInstance(t: Int): SingletonSafeLazy? {
            if (sInstance == null) {
                sInstance = SingletonSafeLazy(t)
            }
            return sInstance
        }
    }

    fun test() {
        println("SingletonSafeLazy")
    }
}
```

### 双重锁校验

描述：
采用双锁机制，安全且在多线程情况下能保持高性能。

```kt
class SingletonDCL {
    companion object {
        val instance by lazy(LazyThreadSafetyMode.SYNCHRONIZED) {
            SingletonDCL()
        }
    }

    fun test() {
        println("SingletonDCL")
    }
}
```

### 静态内部类

描述：
该模式利用了静态内部类延迟初始化的特性，来达到与双重校验锁方式一样的功能。

```kt
class SingletonStatic {
    companion object {
        fun getInstance() = Holder.instance
    }

    private object Holder {
        val instance = SingletonStatic()
    }

    fun test() {
        println("SingletonStatic")
    }
}
```

### 总结

为什么需要单例，好多场景都能用得到，用于多个模块共享操作同一功能模块。5种实现方式区别对比：

| 实现方式    | 是否lazy初始化 | 是否是线程安全 | 实现难易程度 | 优缺点                                            |
| ------- | --------- | ------- | ------ | ---------------------------------------------- |
| 饿汉      | 否         | 是       | 易      | 优点：没有加锁，执行效率会提高。<br>缺点：类加载时就初始化，浪费内存，易产生垃圾对象。  |
| 懒汉      | 是         | 否       | 易      | 优点：起到了延时初始化<br>缺点：线程不安全                        |
| 线程安全的懒汉 | 是         | 是       | 易      | 优点：第一次调用才初始化，避免内存浪费<br> 缺点：必须加锁才能保证单例，加锁会影响效率。 |
| 双重锁校验   | 是         | 是       | 较复杂    | 线程安全，效率高                                       |
| 静态内部类   | 是         | 是       | 一般     | 优点：线程安全，效率高<br>缺点：可以被反射破坏                      |

关于怎么给单例传参，参考[Kotlin实战指南七：单例模式_51CTO博客_kotlin 单例模式](https://blog.51cto.com/zhaoyanjun/3814869)

### 优缺点

**特点**
全局访问节点，以达到共享资源的目的。

**优点**
- 提供调用速率
- 更有效利用资源
- 防止资源冲突和一致性问题

**缺点**
- 存在竞争条件
- 线程安全问题

### 应用场景

- 资源分享：数据库连接管理
- 配置管理
- 缓存
- 日志管理
- 对象工厂

参考：

[单例模式 | 菜鸟教程](https://www.runoob.com/design-pattern/singleton-pattern.html)

[java设计模式之单例模式_java单例模式_三寸旧城。的博客-CSDN博客](https://blog.csdn.net/liu_da_da/article/details/125425561)