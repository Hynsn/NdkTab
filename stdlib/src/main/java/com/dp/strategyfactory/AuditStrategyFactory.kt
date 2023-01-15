package com.dp.strategyfactory

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