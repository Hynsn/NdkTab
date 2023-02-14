### 介绍

用原型实列指定创建对象的种类，通过拷贝这些实例创建对象。调用者无需关系内部细节，不调用构造函数。
kt中怎么实现原型模式，就需要借助浅拷贝和深拷贝

- 浅拷贝：生成一个新对象，新对象和原对象完全相同，对于非基本数据类型，指向原对象中该对象的内存地址。
- 深拷贝：生产一个新对象，所有对象都会被克隆，包括非基本数据类型。

### 适用场景
- 类初始化资源过多
- 创建对象过程繁琐
- 构造函数复杂
- 循环体中生产大量对象

### kt中实现

#### 浅拷贝

- 方案1：实现clone接口，重写clone方法即可。无需clone中调用成员属性的非基本数据类型的clone方法
- 方案2：使用data class 的copy即可

#### 深拷贝

- 实现clone接口，重写clone方法即可。每个对象都实现clone方法，调用成员属性的非基本数据类型的clone方法

```kt
class Course(val name: String):Cloneable{
    public override fun clone(): Course {
        return super.clone() as Course
    }

    override fun toString(): String {
        return "course($name)"
    }
}

class Student(var name: String,
              var age: Int,
              var course:Course? = null) : Cloneable{

    public override fun clone(): Student {
        val s = super.clone() as Student
        s.course = course?.clone()
        return s
    }

    override fun toString(): String {
        return "name:$name,age:$age $course"
    }
}

data class Student1(val name: String,val course: Course2)
data class Course2(val name: String)

fun main(){
    val s1 = Student1("张三",Course2("二年级三班"))
    val s2 = s1.copy()
    println("(s1==s2) = ${s1 === s2}") //false
    println("s1.c(${System.identityHashCode(s1.course)})==s2.c(${System.identityHashCode(s2.course)}) = ${s1.course===s2.course}") //true

    val cause = Course("语文课")
    val s3 = Student("张三",4,cause)
    val s4 = s3.clone()
    println("s3: $s3,s4: $s4")
    println("(s3==s4) = ${s3 === s4}") //false
    println("s1.c(${System.identityHashCode(s3.course)})==s2.c(${System.identityHashCode(s4.course)}) = ${s3.course===s4.course}") //true
}
```

输出：
> (s1==s2) = false
> s1.c(1134712904)==s2.c(1134712904) = true
> s3: name:张三,age:4 course(语文课),s4: name:张三,age:4 course(语文课)
> (s3==s4) = false
> s1.c(1784662007)==s2.c(997110508) = false

因为深拷贝平常开发用的比较少，本文暂时不作深入讨论，可以参考：[Kotlin中实现对象深拷贝的3种方式](http://events.jianshu.io/p/d9c49138b504) 。ps：我复制过去试了一下kotlin 1.8 反射似乎有所变化，无法运行。

### 总结

#### 优缺点

优点：
1. 性能高，java自带的原型模式基于二进制流拷贝
2. 避免调用构造函数
3. 简化对象的创建过程

缺点：
1. 必须配备clone方法或可拷贝方法
2. 违反开闭原则
3. 浅拷贝和深拷贝要运用得当。当对象间存在多重嵌套引用时，每一层都需要实现比较麻烦。
4. 原型模式破坏了单列

这里补充一下：
**对象的创建过程**
1. new指令
2. 类加载检测
虚拟机遇到new指令时，首先进行类加载检测：
(1)，检测new指令的参数是否能在常量池中定位类的符号引用
(2)，检测这个符号引用是否进行过类的加载解析和初始化，没有则先对该类进行加载。
3. 对象内存分配
创建一个对象所需要的内存在类加载完成时就能够确定，内存分配是指在堆中划分出一块和对象大小的对应内存出来。
4. 值初始化
jvm会初始化分配好的内存，将其设置为0值
5. 设置对象头
(1)，markword 标记信息：存储对象自身运行时的数据：如hascode、gc年龄分代、锁标志、锁信息等；
(2)，klassword 类型指针：指向它对应的类元数据，VM用这个确定属于哪个类等实例；
6. 执行<init>
类的构造函数，对属性进行赋值。