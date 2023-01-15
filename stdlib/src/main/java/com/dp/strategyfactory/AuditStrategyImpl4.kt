package com.dp.strategyfactory

class AuditStrategyImpl4 : AuditStrategy {
    override fun isSupport(form: LeaveForm): Boolean {
        return form.days == 1 && form.type == 0
    }

    override fun audit(form: LeaveForm) {
        println("form:$form")
        println("一天病假无需审批，自动通过")
    }

    override val priority: Int = 0
    override val name: String = AuditStrategyImpl4::class.java.simpleName
}