package com.dp.strategyfactory

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