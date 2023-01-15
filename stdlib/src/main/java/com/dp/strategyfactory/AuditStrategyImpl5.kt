package com.dp.strategyfactory

class AuditStrategyImpl5 : AuditStrategy {
    override fun isSupport(form: LeaveForm): Boolean {
        return form.days > 1 && form.type == 0
    }

    override fun audit(form: LeaveForm) {
        println("form:$form")
        println("一天以上病假，需上级审批")
    }

    override val priority: Int = 0
    override val name: String = "一天病假审批规则"
}