@[TOC](文章目录)

---

#### 目的

降低对象之间的耦合；
增加程序的可复用、可扩展性和可维护性

#### 1. 单一职责

一个类应该有且仅有一个引起它变化的原因

```kt
interface LaptopFunction {
    fun startUp()
    fun shutDown()
}
interface LaptopProperty {
    val cpu:String
    val size:Int
    // 新增分辨率
    val resolution:String
}

class MacLaptopFunction : LaptopFunction {
    override fun startUp() {
        println("开机")
    }

    override fun shutDown() {
        println("关机")
    }
}

class MacLaptopProperty: LaptopProperty {
    override val cpu: String = "M1"
    override val size: Int = 1
    override val resolution: String = "1080*960"
    override fun toString(): String {
        return "com.dp.sevenrule.MacLaptopProperty(cpu='$cpu', size=$size, resolution='$resolution')"
    }

}

data class MacBook(
    val property: MacLaptopProperty,
    val function: MacLaptopFunction
)

fun main(){
    val mac = MacBook(MacLaptopProperty(), MacLaptopFunction())
    mac.run {
        println(property.toString())
        function.startUp()
        function.shutDown()
    }
}
```

**作用：**

- 降低类的复杂性
- 提高可读性和可维护性
- 降低修改引起的风险

**注意事项**

- 高内聚：减少大而全，避免不相关功能的耦合
- 低耦合：减少所需依赖和被依赖的类
  那种设计最好？
- 需求（变更和复杂度） -> 职责-> 设计粒度
- 没有好的设计，只有更合适的设计。

#### 2. 开闭原则

对扩展开放，对修改关闭。需求在变化时，不修改源代码的基础上扩展功能。
不“开闭”的坏处：牵一发动全身。

```kt
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
```

**好处：**

- 测试简单
- 可复用性强
- 稳定性高

**如何实现？**
接口和抽象类
开放和关闭

- 拓展开放：应对变化
- 修改关闭：保持稳定

**注意事项：**

- 用抽象构建框架，用实现扩展细节
- 参数类型、引用类型尽量使用接口或抽象类
- 抽象层尽量保持稳定：接口和抽象只负责定义方法，不负责具体实现

#### 3. 迪米特法则（最少知识原则）

一个类对于其他类知道的越少越好，只与直接的朋友通信。

- 朋友：有耦合（依赖、关联、组合、聚合）关系的对象

- 直接的朋友：成员变量、方法参数、方法返回值中的类

- 遵循该法则的设计模式：门面模式、中介模式
  
  ```kt
  /**
   * 卡
   */
  class Card(var balance: Int = 10)
  
  /**
   * 顾客
   */
  class Customer(
      val card: Card = Card()
  )
  
  /**
   * 店铺
   */
  class SurfShop {
      fun chargeCustomer(c: Customer, f: Int) {
          c.card.balance -= f
      }
  }
  
  class Customer1(val card: Card1 = Card1()) {
      fun pay(f: Int) {
          card.deduct(f)
      }
  }
  
  class Card1(var balance: Int = 10) {
      fun deduct(f: Int) {
          balance -= f
      }
  }
  
  class SurfShop1 {
      fun chargeCustomer(c: Customer1, f: Int) {
          c.pay(f)
      }
  }
  
  fun main() {
      val s = SurfShop()
      val c = Customer()
      s.chargeCustomer(c, 10)
      println("finish: ${c.card.balance}")
  
      val s1 = SurfShop1()
      val c1 = Customer1()
      s1.chargeCustomer(c1, 10)
      println("finish: ${c1.card.balance}")
  }
  ```
  
  **好处：**

- 降低耦合，提高模块功能的独立性

- 非常实用，能直接用于开发环境
  
  **注意事项：**
  
  不要干

- objA.getObjB().doSomething()

- objA.getObjB().getObjC.doSomething()

- 避免过度使用，不然会存在大量中间类

#### 4. 依赖倒置

高层模块 -> 接口/抽象类 <- 底层模块

```kt
class BWM {
    fun rentBWM(model: String) {
        println("BWM $model")
    }
}

interface CarManufactory {
    fun rent(model: String)
}

class BWM1 : CarManufactory {
    override fun rent(model: String) {
        println("BWM1 $model")
    }
}

class Mercedes {
    fun rentMercedes(model: String) {
        println("Mercedes $model")
    }
}

class Mercedes1 : CarManufactory {
    override fun rent(model: String) {
        println("Mercedes1 $model")
    }
}

class CarRentalAgency {
    fun rentCar(brand: String, model: String) {
        when (brand) {
            "BWM" -> {
                BWM().rentBWM(model)
            }
            "Mercedes" -> {
                Mercedes().rentMercedes(model)
            }
        }
    }
}

class CarRentalAgency1 {
    fun rentCar(cm: CarManufactory, model: String) {
        cm.rent(model)
    }
}

fun main() {
    val agency = CarRentalAgency()
    agency.rentCar("BWM", "T3")
    agency.rentCar("Mercedes", "AL")

    val agency1 = CarRentalAgency1()
    agency1.rentCar(BWM1(), "T3")
    agency1.rentCar(Mercedes1(), "AL")
}
```

**内容：**

- 高层不应该直接依赖底层，两者应该基于抽象
- 抽象不应该依赖细节，细节依赖抽象
- 应用于工厂方法设计模式

**优点：**

- 架构更稳定
- 更好的应对需求的变化

**面向接口编程：**

- 程序要依赖于抽象接口，不要依赖于具体实现
- 抽象比细节稳定

#### 5. 合成（聚合/组合）复用原则

**内容：**
尽量使用对象聚合/组合，而不是继承达到复用。

**聚合 vs 组合 vs 继承**

- 聚合 has -A
- 组合 contains -A
- 继承 is -A

```kt
  /**
   * 汽油车
   */
  open class GasolineCar {
      open fun move() {
          println("GasolineCar move")
      }
  }

  /**
   * 电动车
   */
  class ElectricCar {
      fun move() {
          println("ElectricCar move")
      }
  }

  class RedGasolineCar : GasolineCar() {
      override fun move() {
          println("RedGasolineCar move")
      }
  }

  class BlueGasolineCar : GasolineCar() {
      override fun move() {
          println("BlueGasolineCar move")
      }
  }

  interface Energy {

  }

  class Gasoline : Energy {

      override fun toString(): String {
          return "Gasoline()"
      }

  }

  class Electric : Energy {

      override fun toString(): String {
          return "Gasoline()"
      }

  }

  interface Color {

  }

  class Bule : Color {

      override fun toString(): String {
          return "Bule()"
      }

  }

  class Red : Color {

      override fun toString(): String {
          return "Red()"
      }

  }

  class Car(val energy: Energy, val color: Color) {

      fun move() {
          println("$energy $color move")
      }

  }

  fun main() {

      val r1 = RedGasolineCar()
      r1.move()

      val c = Car(Gasoline(), Bule())
      c.move()

  }
```

**继承复用 vs 合成复用 继承复用**

- 优点：简单，实现容易
- 缺点：破坏了封装性，耦合度高、限制灵活性，进行扩展比较麻烦
  合成复用
- 优点：维持封装性，降低耦合度，灵活性高
- 缺点：有较多对象时需要管理

#### 6. 接口隔离原则

1.客户端不应该依赖它不用的接口 -> 低耦合

- 客户依赖了不需要的接口，就面临不需要接口变动带来的风险
- 提倡客户不应该被迫使用对其无用的方法或功能

2.类之间的依赖应该建立在最小的接口上面 -> 高内聚

- 把没有关系的接口合并在一起，会形成一个臃肿的大接口，这是对职责分配和接口的污染
- 最小接口：满足项目需求的相似功能
- 把膨大臃肿的接口拆成更小更具体的接口
  接口隔离：多个专门的接口 > 单一的总接口

```kt
interface BadCharacterSkill {
    fun basicAttach()
    fun magicAttach()
    fun recover()
}
class Monster : BadCharacterSkill {
    override fun basicAttach() {
        println("Monster basicAttach")
    }

    override fun magicAttach() {
        // 空实现
    }

    override fun recover() {
        // 空实现
    }
}

class MonsterBoss : BadCharacterSkill {
    override fun basicAttach() {
        println("MonsterBoss basicAttach")
    }

    override fun magicAttach() {
        println("MonsterBoss magicAttach")
    }

    override fun recover() {
        println("MonsterBoss recover")
    }
}

interface BasicBadCharacterSkill {
    fun basicAttach()
}

interface AdvanceBadCharacterSkill {
    fun magicAttach()
    fun recover()
}

class Monster1 : BasicBadCharacterSkill {
    override fun basicAttach() {
        println("Monster1 basicAttach")
    }
}

class MonsterBoss1 : BasicBadCharacterSkill, AdvanceBadCharacterSkill {
    override fun basicAttach() {
        println("MonsterBoss1 basicAttach")
    }

    override fun magicAttach() {
        println("MonsterBoss1 magicAttach")
    }

    override fun recover() {
        println("MonsterBoss1 recover")
    }
}
```

**注意事项：**
**设计粒度**

- 设计粒度上太小会适得其反
- 设计粒度参考，一个接口只服务于一个子模块或业务逻辑

**接口隔离原则 vs 单一职责原则**

- 约束偏向：接口隔离偏向约束架构设计，单一职责偏向约束业务
- 细化程度：单一职责更精细，接口隔离注重相似接口的隔离。接口隔离可以是单一职责的共同接口

#### 7. 里氏替换原则

任何基类可以出现的地方，子类一定可以出现。

```kt
open class Calculator {
    open fun calculate(n1: Int, n2: Int): Int {
        return n1 + n2
    }
}

class SuperCalculator : Calculator() {
    override fun calculate(n1: Int, n2: Int): Int {
        return n1 - n2
    }

    fun subtract(n1: Int, n2: Int): Int {
        return n1 - n2
    }
}

abstract class Calculator1 {
    abstract fun stringToList(s: String): ArrayList<String>
}

class SuperCalculator1 : Calculator1() {
    // 这样写编译器会报错
    /*override fun stringToList(s: String): List<String> {
        return listOf()
    }*/
    override fun stringToList(s: String): ArrayList<String> {
        return arrayListOf()
    }
}

object StringProcessor {
    fun stringToList(c: Calculator1, s: String): ArrayList<String> {
        return c.stringToList(s)
    }
}


fun main() {
    // 1
    val c1 = Calculator()
    val s1 = SuperCalculator()
    val sum = s1.calculate(10, 5)
    println("sum $sum")

    // 3
    StringProcessor.stringToList(SuperCalculator1(), "test")
    // 4
    val c2 = Calculator()
    val c3 = SuperCalculator()
    val x = 1
    val y = 2
    val addRet = c2.calculate(x, y)
    println("addRet $addRet")

    val subRet = c3.subtract(x, y)
    println("addRet $subRet")
}
```

**Why里氏替换？**

- 继承给程序带来入侵性
- 保证程序升级后的兼容性
- 避免程序出错

**规范**
原则

- 保证基类所拥有的性质在子类中依然成立
- 子类扩展父类功能，但不能改变父类原有功能

**如何规范遵循里氏替换原则**

1. 子类必须完全实现父类的抽象方法，但不能覆盖父类的非抽象方法
2. 子类可以实现自己特有的方法
3. 子类的方法实现父类抽象的方法时，反法的后置条件要比父类更严格
4. 子类的实列可以替代父类的实列，但反之不成立

**注意事项**
里氏替换原则 = 父类不能被子类替换 = 继承复用的规范

- 不遵守规范 -> 当前代码没有问题，未来出错率会高
- 聚合/组合 > 继承（合成复用原则）
