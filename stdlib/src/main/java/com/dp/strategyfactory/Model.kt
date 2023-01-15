package com.dp.strategyfactory

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
