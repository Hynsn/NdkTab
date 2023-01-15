package com.dp.strategyfactory

class AuditStrategyImpl2 : AuditStrategy {
    override fun isSupport(form: LeaveForm): Boolean {
        return form.days > 3 && form.type == 1
    }

    override fun audit(form: LeaveForm) {
        println("form:$form")
        println("三天以上丧家，需上级审批")
    }

    override val priority: Int = 0
    override val name: String = AuditStrategyImpl2::class.java.simpleName
}