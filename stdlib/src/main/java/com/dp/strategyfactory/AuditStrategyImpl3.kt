package com.dp.strategyfactory

class AuditStrategyImpl3 : AuditStrategy {
    override fun isSupport(form: LeaveForm): Boolean {
        return form.employee.level == 9
    }

    override fun audit(form: LeaveForm) {
        println("form:$form")
        println("总经理请假无需审批，自动通过")
    }

    override val priority: Int = 999
    override val name: String = "总经理请假审批规则"
}