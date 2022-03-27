A C++ algorithm std::lib.

### 线性表 

- [顺序存储]
Array 数组类：静态 动态
List -> seqlist 静态 动态

- [链式存储]
单链表
StaticLinkList
循环链表
双向链表
双向循环链表

### Stack - 栈
StaticStack LinkStack
### Queue - 队列
StaticQueue LinkQueue

### SP、Exception、KMP、Sort
- SmartPointer, SharedProinter
- Exception
- HString
- Sort - 选择、插入、冒泡、希尔、归并、快排

### GTree - 树
查找、插入、删除、属性操作、层次遍历
### BTree - 二叉树
查找、插入、删除、清除、属性操作、层次遍历、比较和相加

刷题总结

###

#### 数组
1、数组中重复的数字
解法
#1 先排序，再遍历 时间复杂度O(nlogn)
#2 使用HashMap 时间复杂度O(n) 空间复杂度O(n)
#3 利用数组的下表 +code
2、二维数组查找
一个每一行从左到右递增、每列从上到下递增的二维数组，判断该数组中是否包含某一整数。
归纳总结能力



题目变形
不修改数组找出重复的数字（只能通过查找）+code
参考二分查找算法增加统计的同时找出结果 时间复杂度O（nlogn）空间复杂度O(1)

代码设计原理
异常安全性

单例
三种实现方式区别
