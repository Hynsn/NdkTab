package com.dp.strategyfactory

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
