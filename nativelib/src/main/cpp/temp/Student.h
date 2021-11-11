#pragma once //保证头文件只被编译一次

#ifndef SELECTSORT_STUDENT_H
#define SELECTSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;// 软件工程行业 用多了会造成空污染

// 运算符重载 享元函数相关概念
struct Student
{
	string name;
	int score;
	// 运算符重载
	bool operator<(const Student &otherStudent) {
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;// 分数不相等时 按字母排序
	}
	// 享元函数
	friend ostream& operator<<(ostream &os,const Student &student) {
		os << "Student: " << student.name << " " << student.score << endl;
		return os;
	}
};

#endif // !SELECTSORT_STUDENT_H
