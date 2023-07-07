### 概念

允许多个对象按顺序处理请求或任务

#### 角色介绍

- Handler 处理器接口
- 具体处理器 ConcreteHandler

#### UML

一张图片

### 代码实现
![atm](https://sourcemaking.com/files/sm/images/patterns/Chain_of_responsibility_example.png)
```kt
// 一段代码
```

### 优缺点

优点
- 分离发送着和接收者
- 链中的灵活性
- 易于扩展和维护

缺点
- 无法保证处理请求
- 性能开销较大
- 调试复杂度高

### 应用场景

有多个对象可以处理请求，动态添加、删除修改请求处理器。
- 中间件
- GUI时间处理器
- 异常处理
- 工作流

### 总结

一段总结

参考：

- a

- b

- c
