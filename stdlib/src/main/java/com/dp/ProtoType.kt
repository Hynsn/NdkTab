package com.dp

class Course(val name: String):Cloneable{
    public override fun clone(): Course {
        return super.clone() as Course
    }

    override fun toString(): String {
        return "course($name)"
    }
}

class Student(var name: String,
              var age: Int,
              var course:Course? = null) : Cloneable{

    public override fun clone(): Student {
        val s = super.clone() as Student
        s.course = course?.clone()
        return s
    }

    override fun toString(): String {
        return "name:$name,age:$age $course"
    }
}

data class Student1(val name: String,val course: Course2)
data class Course2(val name: String)

fun main(){
    val s1 = Student1("张三",Course2("二年级三班"))
    val s2 = s1.copy()
    println("(s1==s2) = ${s1 === s2}") //false
    println("s1.c(${System.identityHashCode(s1.course)})==s2.c(${System.identityHashCode(s2.course)}) = ${s1.course===s2.course}") //true

    val cause = Course("语文课")
    val s3 = Student("张三",4,cause)
    val s4 = s3.clone()
    println("s3: $s3,s4: $s4")
    println("(s3==s4) = ${s3 === s4}") //false
    println("s1.c(${System.identityHashCode(s3.course)})==s2.c(${System.identityHashCode(s4.course)}) = ${s3.course===s4.course}") //true
}