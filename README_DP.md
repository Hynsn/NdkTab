### 7大原则

#### 目的

降低对象之间的耦合；
增加程序的可复用、可扩展性和可维护性

#### 单一职责

一个类应该有且仅有一个引起它变化的原因
作用：

- 降低类的复杂性
- 提高可读性和可维护性
- 降低修改引起的风险
  注意事项
- 高内聚：减少大而全，避免不相关功能的耦合
- 低耦合：减少所需依赖和被依赖的类
  那种设计最好？
- 需求（变更和复杂度） -> 职责-> 设计粒度
- 没有好的设计，只有更合适的设计。

#### 开闭原则

对扩展开放，对修改关闭。需求在变化时，不修改源代码的基础上扩展功能。
不“开闭”的坏处：牵一发动全身
好处：

- 测试简单
- 可复用性强
- 稳定性高
  如何实现？
  接口和抽象类
  开放和关闭
- 拓展开放：应对变化
- 修改关闭：保持稳定
  注意事项：
- 用抽象构建框架，用实现扩展细节
- 参数类型、引用类型尽量使用接口或抽象类
- 抽象层尽量保持稳定：接口和抽象只负责定义方法，不负责具体实现

#### 迪米特法则（最少知识原则）

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
  
  ##### 好处：

- 降低耦合，提高模块功能的独立性

- 非常实用，能直接用于开发环境
  
  ##### 注意事项：
  
  不要干

- objA.getObjB().doSomething()

- objA.getObjB().getObjC.doSomething()

- 避免过度使用，不然会存在大量中间类

#### 依赖倒置

高层模块 -> 接口/抽象类 <- 底层模块
内容：

- 高层不应该直接依赖底层，两者应该基于抽象

- 抽象不应该依赖细节，细节依赖抽象

- 应用于工厂方法设计模式
  优点：

- 架构更稳定

- 更好的应对需求的变化
  面向接口编程：

- 程序要依赖于抽象接口，不要依赖于具体实现

- 抽象比细节稳定
  
  #### 合成（聚合/组合）复用原则
  
  内容：
  尽量使用对象聚合/组合，而不是继承达到复用。
  聚合 vs 组合 vs 继承

- 聚合 has -A

- 组合 contains -A

-  继承 is -A 
  
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

##### 继承复用 vs 合成复用 继承复用

- 优点：简单，实现容易

- 缺点：破坏了封装性，耦合度高、限制灵活性，进行扩展比较麻烦
  合成复用

- 优点：维持封装性，降低耦合度，灵活性高

- 缺点：有较多对象时需要管理

#### 接口隔离原则

1.客户端不应该依赖它不用的接口 -> 低耦合

- 客户依赖了不需要的接口，就面临不需要接口变动带来的风险
- 提倡客户不应该被迫使用对其无用的方法或功能

2.类之间的依赖应该建立在最小的接口上面 -> 高内聚

- 把没有关系的接口合并在一起，会形成一个臃肿的大接口，这是对职责分配和接口的污染
- 最小接口：满足项目需求的相似功能
- 把膨大臃肿的接口拆成更小更具体的接口
  接口隔离：多个专门的接口 > 单一的总接口
  注意事项：
  设计粒度
- 设计粒度上太小会适得其反
- 设计粒度参考，一个接口只服务于一个子模块或业务逻辑
  接口隔离原则 vs 单一职责原则
- 约束偏向：接口隔离偏向约束架构设计，单一职责偏向约束业务
- 细化程度：单一职责更精细，接口隔离注重相似接口的隔离。接口隔离可以是单一职责的共同接口

#### 里氏替换原则

任何基类可以出现的地方，子类一定可以出现。
Why里氏替换？

- 继承给程序带来入侵性
- 保证程序升级后的兼容性
- 避免程序出错
  规范
  原则
- 保证基类所拥有的性质在子类中依然成立
- 子类扩展父类功能，但不能改变父类原有功能
  如何规范遵循里氏替换原则
1. 子类必须完全实现父类的抽象方法，但不能覆盖父类的非抽象方法
2. 子类可以实现自己特有的方法
3. 子类的方法实现父类抽象的方法时，反法的后置条件要比父类更严格
4. 子类的实列可以替代父类的实列，但反之不成立
   注意事项
   里氏替换原则 = 父类不能被子类替换 = 继承复用的规范
- 不遵守规范 -> 当前代码没有问题，未来出错率会高
- 聚合/组合 > 继承（合成复用原则）
