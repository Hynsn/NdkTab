### 背景

本文主要介绍策略模式，及如何结合简单工厂优化代码。

### 策略模式

**定义**

定义一系列的算法或判断逻辑，将算法或判断逻辑封装起来，让它们可以相互替换，让算法或判断逻辑独立于客户。

核心定义接口，将公共行为抽象起来，具体的逻辑又封装到不同的策略类中。

**组成**

抽象策略类、具体策略类、上下文场景类

**优缺点**

优点：

- 可以动态修改对象的行为

- 避免使用多重条件选择语句

缺点：

- 客户端必须知道所有的策略类，并自行决定使用哪个策略类

- 策略模式将造成产生很多策略类

**使用场景**

- 系统需要快速切换算法或动作或系统中有一些类仅仅行为不同。

- 存在多重条件选择语句时。

### 示例

下面以钉钉员工请假为例子举例

```kt
/**
 * 请假表单
 */
data class LeaveForm(
    val employee: Employee,
    val days: Int,
    val reason: String,//请假原因
    val type: Int // 类型：0病假，1婚丧假，2年假
)

/**
 * 员工
 */
data class Employee(
    val name: String,
    val level: Int
)
```

```kt
interface AuditStrategy {
    // 判断条件是否匹配
    fun isSupport(form: LeaveForm):Boolean

    // 审核业务逻辑
    fun audit(form: LeaveForm)

    // 规则冲突时的优先级
    val priority: Int

    // 规则名称
    val name: String
}
```

```kt
class AuditStrategyImpl1 : AuditStrategy {
    override fun isSupport(form: LeaveForm): Boolean {
        return form.days <= 3 && form.type == 1
    }

    override fun audit(form: LeaveForm) {
        println("form:$form")
        println("三天以下丧假无需审批，自动通过")
    }

    override val priority: Int = 0
    override val name: String = "三天以下丧假"
}
```

```kt
/**
 * 策略工厂类
 *
 */
object AuditStrategyFactory {

    private val auditStrategyList = ArrayList<AuditStrategy>()

    init {
        auditStrategyList.add(AuditStrategyImpl1())
        auditStrategyList.add(AuditStrategyImpl2())
        auditStrategyList.add(AuditStrategyImpl3())
        auditStrategyList.add(AuditStrategyImpl4())
        auditStrategyList.add(AuditStrategyImpl5())
    }

    fun getAuditStrategy(form: LeaveForm): AuditStrategy? {
        var auditStrategy: AuditStrategy? = null
        for (strategy in auditStrategyList) {
            if (strategy.isSupport(form)) {
                if (auditStrategy == null) {
                    auditStrategy = strategy
                } else {
                    // 如果发现优先级相同的其他策略，直接抛出异常
                    if (strategy.priority == auditStrategy.priority) {
                        throw RuntimeException("[${auditStrategy.name}]:[${strategy.name}] 优先级相同")
                    }
                    // 如果有更高的优先级，替代现有规则
                    else if (strategy.priority > auditStrategy.priority) {
                        auditStrategy = strategy
                    }
                }
            }
        }
        return auditStrategy
    }
}
```

代码重构时，需要先抽象接口或类，然后编写静态工厂。最后实现各个策略，最后将各个策略添加进来。

```kt
class LeaveServiceOld {

    // 审核
    fun audit(leaveForm: LeaveForm) {
        when {
            (leaveForm.days <= 3 && leaveForm.type == 1) -> {
                println("三天以下丧家无需审批，自动通过")
            }

            (leaveForm.days > 3 && leaveForm.type == 1) -> {
                println("三天以上丧家，需上级审批")
            }

            (leaveForm.employee.level == 9) -> {
                println("总经理请假无需审批，自动通过")
            }

            (leaveForm.days == 1 && leaveForm.type == 0) -> {
                println("一天病假无需审批，自动通过")
            }

            (leaveForm.days > 1 && leaveForm.type == 0) -> {
                println("一天以上病假，需上级审批")
            }
        }
    }
}

fun main() {
    val service = LeaveServiceOld()
    val employee = Employee("张三", 9)
    val form = LeaveForm(employee, 4, "生病了", 3)
    service.audit(form)

    val factory = AuditStrategyFactory.getAuditStrategy(form)
    factory?.audit(form)
}
```

### 总结

静态工厂方法（简单工厂模式）严格来说不能属于设计模式，策略模式不能消除if else，但可以结合静态工厂方法结合去除代码中的if else。


