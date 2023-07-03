### 概念

把请求转化为独立的对象

#### 角色介绍

- Command 命令
- 具体命令 ConcreteCommand

#### UML

一张图片

### 代码实现

```kt
interface Command {
    fun execute(vararg arg: String):Int
}
class Print : Command {
    override fun execute(vararg arg: String): Int {
        println("Print:${arg.toList()}")
        return 1
    }
}
class None : Command {
    override fun execute(vararg arg: String): Int {
        println("None:${arg.toList()}")
        return 1
    }
}
class CommandProcessor {
    fun handle(className: String, vararg arg: String): Int? {
        try {
            val pkg = this.javaClass.`package`?.name
            val command: Command = Class.forName("$pkg.$className").newInstance() as Command
            return command.execute(*arg)
        } catch (e: Exception) {
            println("未知命令")
            e.printStackTrace()
        }
        return null
    }
}

fun main() {
    val cp = CommandProcessor()
    cp.handle("None", "12")
    cp.handle("Print", "12", "123")
    cp.handle("", "12", "123")
}
```
输出
>None:[12]
Print:[12, 123]
未知命令
java.lang.ClassNotFoundException: com.dp.command.
at java.base/jdk.internal.loader.BuiltinClassLoader.loadClass(Unknown Source)
at java.base/jdk.internal.loader.ClassLoaders$AppClassLoader.loadClass(Unknown Source)
at java.base/java.lang.ClassLoader.loadClass(Unknown Source)
at java.base/java.lang.Class.forName0(Native Method)
at java.base/java.lang.Class.forName(Unknown Source)
at com.dp.command.CommandProcessor.handle(CommandProcessor.kt:7)
at com.dp.command.CommandProcessorKt.main(CommandProcessor.kt:21)
at com.dp.command.CommandProcessorKt.main(CommandProcessor.kt)

### 优缺点

优点
- 动作封装
- 解偶发送者和接收者
- 可扩展性
- 简化和集中错误处理
- 支持撤销和重做功能
- 易于实现宏命令和组合命令

缺点
- 复杂度增加
- 性能开销

### 应用场景

列举应用场景
- 文本编辑器
- 图新编辑器
- 不同进程间交互
### 总结

一段总结

参考：

- a

- b

- c
