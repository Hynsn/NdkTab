### 概念

定义算法骨架、代码模版

#### 角色介绍

- Abstract Class
- Concrete Class

#### UML

![](https://www.runoob.com/wp-content/uploads/2014/08/template_pattern_uml_diagram.jpg)

### 代码实现

```kt
abstract class Game {
    protected abstract fun initialize()
    protected abstract fun startPlay()
    protected abstract fun endPlay()

    // 模版
    fun play(){
        initialize()
        startPlay()
        endPlay()
    }
}
/**
 * 板球游戏
 */
class Cricket : Game() {
    override fun initialize() {
        println("Cricket initialize")
    }

    override fun startPlay() {
        println("Cricket startPlay")
    }

    override fun endPlay() {
        println("Cricket endPlay")
    }
}
/**
 * 足球游戏
 */
class Football : Game() {
    override fun initialize() {
        println("Football initialize")
    }

    override fun startPlay() {
        println("Football startPlay")
    }

    override fun endPlay() {
        println("Football endPlay")
    }
}
fun main() {
    var game:Game = Cricket()
    game.play()
    game = Football()
    game.play()
}
```

### 优缺点

优点
- 代码复用
- 统一代码框架
- 封装不变，扩展可变

缺点 
- 增加复杂性
- 父类（基类）改动影响大
   
### 应用场景

一次性实现算法的不变部分，集中公共行避免代码重复。
- 数据库访问，Spring持久层处理的步骤：获取会话-》开始事务-》提交到数据库-》提交事务-》关闭会话
- GUI设计，BaseMVP BaseMVVM封装
- 框架和库
  
### 总结

该模式可以很好的分离代码流程通用部分和具体实现部分，从而提高代码灵活性和可维护性。
