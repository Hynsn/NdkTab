package com.dp.strategyfactory

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