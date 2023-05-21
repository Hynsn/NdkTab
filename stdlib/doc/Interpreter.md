## 设计模式

设计模式是针对常见问题的通用解决方案。

比如保证一个类只有一个实例 -> 单例

搭建两个不兼容接口之间的桥梁 ->适配器

为Library、framework提供一个简洁的接口 ->外观

设计模式的必要性

没有设计模式：代码维护成本高，改进空间小

优点

- 减少垃圾代码，提高代码可维护性和可扩展性

- 减少沟通成本

- 开拓思维，提升解决问题的能力

### 分类

### 创建性

- [x]  Abstract Factory

- [x]  Builder

- [x]  Factory Method

- [x]  Prototype

- [x]  Singleton

#### 结构型

帮助我们组合各种对象，实现更好更灵活的结构。

- [x]  Adapter

- [ ]  Bridge

- [ ]  Composite

- [ ]  Decorator

- [ ]  Facade

- [ ]  Flyweight

- [ ]  Proxy

#### 行为型

- [ ]  Chain of Responsiblity

- [ ]  Command

- [ ]  interpreter

- [ ]  iterator

- [ ]  Meidator

- [ ]  Memento

- [ ]  Observer

- [ ]  State

- [x]  Strategy

- [ ]  TemplateMethod

- [ ]  Visitor

一个专门用来处理语言或者解析表达式的设计模式，比如sql、正则
将解析和解释分离，特别适合处理特定领域的语言。
主要组件：
abstract Expression
terminal expression
non-terminal expression
context

优点：
1. 易于扩展或者修改
2. 灵活
3. 关注点分离
4. 代码复用
缺点：
5. 性能问题
6. 调试困难
7. 复杂性增加
8. 实用性有限

适用场景
某个特定类型问题发生频率足够高。
1. 领域特定语言
2. 复杂输入解释
3. 可扩展的语言结构
4. 日志处理：适用脚本语言或编程语言处理日志时，有很多服务会产生大量日志，需要对日志进行解析生成报表，各服务的日志格式不同数据要素相同。
应用：
5. 编译器、解释器
6. 配置文件解析
7. 查询语言解析