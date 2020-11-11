#include <jni.h>
#include <string>

#include <iostream>

#include <android/log.h>

#include "Mylib.h"

using namespace std;

using namespace HynLib;

const char * LOG_TGA = "LOG_TGA";

/*
问题：
在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
设计一个算法，找出出现次数最多的数字。
第6课，以空间换时间Demo
*/
#define TEST6_SEARCH    0
// 智能指针
/*
1、指针生命周期结束时主动释放堆空间
2、一片堆空间最多只能由一个指针标识
3、杜绝指针运算和指针比较
 */
#define TEST9_SMARTPOINTER  0
// 异常
#define TEST11_EXCEPTION  0
// 顶层父类
#define TEST12_TOPOBJECT  0
/*
1、对于线性存储类型不适合使用类类型的对象来作为元素，如果为类的插入操作非常耗时，涉及包含String的对象还涉及到strcpy操作、对象拷贝所以非常耗时
2、对于容器类型的类，可以考虑禁用拷贝构造和赋值操作
3、线性表必须先插入元素，才能使用[]操作符访问元素，因为本质不同所以不能替代数组来使用
*/
// 线性表的顺序存储
#define TEST18_STATICLIST  0
#define TEST19_DYNAMICLIST  0
// 静态数组
#define TEST20_ARRAY  0

// 单链表
/*
顺序表：数据元素类型相对简单，不涉及深拷贝。数据元素相对稳定，访问操作远多于插入和删除操作。
单链表：数据元素类型复杂，复制操作相对耗时。数据元素不稳定，需经常插入和删除访问操作较少。
 */
#define TEST22_LINKLIST 0
// 静态单链表
/*
单链表的一个缺点：长时间使用单链表对象频繁增加和删除数据，堆空间会产生大量的内存碎片导致系统运行缓慢。
单链表的clear、remove操作需考虑异常安全，remove 操作后current指向下一个节点。
 注，子类的构造函数和析构函数是不能发生多态的，调用构造函数和析构函数必须要是当前类的实现版本
 */
#define TEST22_STATICLINKLIST 0


// 共享智能指针
/*
智能指针使用约定
 1、只能用来指向堆空间的单个变量
 2、不同类型智能指针不要混合使用
 3、不要使用delete 释放智能指针指向的堆空间
 */
#define TEST28_SHAREDPOINTER 0

// 数组栈，特殊的线性表唯一特性 先进后出。
// 使用原生数组作为存储结构，存在缺点就是，链表构造函数和析构函数初始化时需要频繁执行。
#define TEST34_STATICSTACK 0

// 链式栈，栈非常适用于就近匹配的场合
#define TEST35_LINKSTACK 0

// 数组队列，先进先出，使用原生数组实现容量由模板参数决定，采用循环计数法实现队列的操作
#define TEST36_STATICQUEUE 0

#define TEST36_LINKQUEUE 0

/**
 * KMP子串查找算法
 * 匹配失败时向右移动的位数和目标串无关，和子串有关
 * 移动位数 = 已匹配字符数 - 对应的部分匹配值
 * 任意子串都存在一个唯一的部分匹配表？？
 * KMP算法 -> 子串 ->部分匹配值 -> 最终转换为求子串的部分匹配表
 */
#define TEST39_HSTRING 0

#define TEST44_RECURSION 0

/**
 * 排序的稳定性也比较重要，比较和交换是排序的基本操作。时间性能是排序算法好坏的主要条件。
 * 多关键字排序和单关键字排序无本质区别，多关键字排序重载运算符增加判断的条件即可。
 *
 * 选择排序和插入排序时间复杂度都是O(n2)，插入排序是稳定的。
 * 希尔排序时间复杂度突破了O(n2)
 *
 * 归并排序的基本思想：将两个或两个以上的有序序列合并成一个新的有序序列，需要用到递归、一边归并一边排序。
 *
 * 快速排序的基本思想：任取某个元素作为基准将序列划分为左右两个序列，左序列所有元素都小于等于基准，
 * 右序列都大于基准基准位于序列中间。对两个子序列递归的划分，直到所有元素都满足上述条件
 *
 */
#define TEST46_SORT 0

/**
 * 排序过程关键操作就是比较和交换，交换的本质就是元素间的复制。当元素体积较大时 元素交换耗时较大
 *
 */
#define TEST50_SORT 0

/**
 * 树
 *
 *
 */
#define TEST52_GTREE 1

#if TEST6_SEARCH

void search(int a[],int len){
    int sp[1000] = {0};
    int max = 0;
    // 利用下标统计数字出现的次数
    for (int i=0;i<len;i++) {
        sp[a[i]-1]++;
    }
    // 找出出现数字最多的次数
    for (int i=0;i<1000;i++) {
        if(sp[i]>max) max = sp[i];
    }
    // 输出次数最大的数
    for (int i=0;i<1000;i++) {
        if(sp[i]==max) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "imes max num : %d",i+1);
    }
}

#endif

#if TEST9_SMARTPOINTER
class Test
{
public:
    Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Test()");
        cout<<"Test()"<<endl;
    }
    ~Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "~Test()");
        cout<<"~Test()"<<endl;
    }
};
#endif

#if TEST12_TOPOBJECT

class NextTest : public Object
{
};

#endif

#if TEST22_LINKLIST
class Test
{
public:
    Test(){
        throw 0;
    }
};
class Test1 : Object
{
    int v;
public:
    Test1(int k=0){
        v = k;
    }
    bool operator == (const Test1& t){
        return v == t.v;
    }
};
#endif

#if TEST28_SHAREDPOINTER
class Test
{
public:
    int value;

    Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Test()");
    }
    ~Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "~Test()");
    }
};
#endif

#if TEST34_STATICSTACK
class Test : public Object
{
public:
    Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Test()");
    }
    ~Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "~Test()");
    }
};
#endif

#if TEST44_RECURSION
void swap1(char* a,char *b);
// 汉诺塔递归
void HanoiTower(int n,char a,char b,char c){
    if(n==1){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "move: %c --> %c",a,c);
    }
    else{
        HanoiTower(n-1,a,c,b); // 先将n-1块模块由a借助c移动到b
        HanoiTower(1,a,b,c); // 将最下面的木块直接移动到C
        HanoiTower(n-1,b,a,c); //将剩下的n-1块木块从b借助a移动到c
    }
}

void  Allarrange(char *str,int k,int len)
{
    int i;
    if(k==len)
    {
        static int s_i=1;
        //printf("第%d种排列为:\t%s\n",s_i++,str);
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "id %d: %s ",s_i++,str);
    }
    else
    {
        for(i=k;i<=len;i++)
        {
            swap1(str+i,str+k);
            Allarrange(str,k+1,len);
            swap1(str+i,str+k);
        }
    }
}

// 集合全排列，当字符重复时存在bug
void swap1(char* a,char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*
测试存在全排列存在重复的bug
char ddd[] = "aacdd";
permutation(ddd,ddd);
 */
void permutation(char* s,char* p){
    if(*s =='\0'){
        static int s_i = 1;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "id %d: %s ",s_i++,p);
    }
    else{
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if((i==0) || (s[0] != s[i])){
                swap1(&s[0],&s[i]);
                permutation(s+1,p);
                swap1(&s[0],&s[i]);
            }
        }
    }
}

void permutation(char s[],int b,int e)
{
    if((b >= 0)&&(b <= e))
    {
        if(b == e)
        {
            __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "id2: %s ",s);
        }
        else
        {
            int i = 0;

            for(i = b;i <= e;i++)
            {
                int flag = s[b];
                s[b] = s[i];
                s[i] = flag;
                if(s[b] != s[i] || i == b)
                    permutation(s,b+1,e);

                flag = s[b];
                s[b] = s[i];
                s[i] = flag;
            }
        }
    }
}

struct Node{
    int value;
    Node* next;
};

// 创建尾节点为null的链表
Node* create_list(int v,int len){
    Node* ret = NULL;
    Node* slider = NULL;

    for (int i = 0; i < len; i++) {
        Node* n = new Node();
        n->value = v++;
        n->next = NULL;

        if(slider == NULL){
            slider = n;
            ret = n;
        }
        else {
            slider->next = n;
            slider = n;
        }
    }

    return ret;
}

void destory_list(Node* list){
    while (list){
        Node* del = list;
        list = list->next;

        delete del;
    }
}

void print_list(Node* list){
    while (list){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "%d ->",list->value);
        list = list->next;
    }
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "null");
}

Node* reverse(Node* list){
    if(list==NULL || list->next==NULL){
        return list;
    }
    else{
        Node* guard = list->next; // 边节点

        Node* ret = reverse(list->next); // 边节点求逆

        guard->next = list; // 别节点指向原节点

        list->next = NULL;

        return ret;
    }
}

Node* marge(Node* list1,Node* list2){
    if(list1==NULL) return list2;
    else if(list2==NULL) return list1;
    else if(list1->value < list2->value){
        Node* list1_ = list1->next;  // 拆分list1
        Node* list = marge(list1_,list2); // 归并
        list1->next = list; // list1指向归并结果并返回
        return list1;
    }
    else {
        Node* list2_ = list2->next; // 拆分list2
        Node* list = marge(list1,list2_); // 归并
        list2->next = list; // list2指向归并结果并返回
        return list2;
    }
}

/**
 * 函数调用过程：一个特殊的内存区供函数使用，用于保存函数的实参局部变量临时变量等。类似于栈
 * 从起始地址向上增长，存在栈顶指针用于回退。
 *
 */
void r_print_event(Node* list){
    if(list!=NULL){
        r_print_event(list->next);
        if((list->value %2) ==0){
            __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "% d ",list->value);
        }
    }
}

#endif

#if TEST35_LINKSTACK
class Test : public Object
{
public:
    Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Test()");
    }
    ~Test(){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "~Test()");
    }
};

bool is_left(char c){
    return (c=='(') || (c=='[') || (c=='{') || (c=='<');
}
bool is_right(char c){
    return (c==')') || (c==']') || (c=='}') || (c=='>');
}
bool is_quot(char c){
    return (c=='\'') || (c=='\"');
}
bool is_match(char l,char r){
    return (l=='\'') && (r=='\'') ||
            (l=='\"') && (r=='\"') ||
            (l=='(') && (r==')') ||
            (l=='{') && (r=='}') ||
            (l=='[') && (r==']') ||
            (l=='<') && (r=='>');
}

bool scan(const char* s){
    LinkStack<char> stack;
    bool ret = true;
    int i = 0;

    while (ret && s[i]!='\0'){
        if(is_left(s[i])){
            stack.push(s[i]);
        }
        else if(is_right(s[i])) {
            if((stack.size()>0) && is_match(stack.top(),s[i])) stack.pop(); else ret = false;
        }
        else if(is_quot(s[i])){
            // 栈空或者 左符号和右符号不匹配时入栈
            if(stack.size()==0 || !is_match(stack.top(),s[i])) stack.push(s[i]);
            else if(is_match(stack.top(),s[i])) stack.pop();
        }

        i++;
    }

    return ret && (stack.size()==0);
}


#endif

#if TEST39_HSTRING
void test_1(){
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "begin--");

    HString s;
    s = 'D';

    for (int i = 0; i < s.length(); ++i) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "[i]-%c",s[i]);
    }
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "len: %d str: %s",s.length(),s.str());
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "== %d",(s =="D" ? 1 : 0));
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "> %d",(s > "CC" ? 1 : 0));

    HString str1 = "test hollo";
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "start:%d",str1.startWith("tet") ? 1:0);
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "end:%d",str1.endWith("hllo") ? 1:0);

    HString str2 = "";
    str2.insert(0,"test");
    str2.insert(3,"world");
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "str2: %s",str2.str());

    HString str3 = "  test  ";
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "str3: %s",str3.trim().str());

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "end--");
}
#endif


#if TEST50_SORT

#include "ctime"

struct Test :public Object{
    int id;
    int data1[1000];
    double data2[1000];

    bool operator < (const Test& obj){
        return id < obj.id;
    }
    bool operator >= (const Test& obj){
        return id >= obj.id;
    }
    bool operator > (const Test& obj){
        return id > obj.id;
    }
    bool operator <= (const Test& obj){
        return id <= obj.id;
    }
};

class TestProxy : public Object{
protected:
    Test* m_ptest;
public:
//    TestProxy(Test* pTest){
//        m_ptest = pTest;
//    }
    int id(){
        return m_ptest->id;
    }
    int* data1(){
        return m_ptest->data1;
    }
    double * data2(){
        return m_ptest->data2;
    }

    Test & test() const {
        return *m_ptest;
    }

    bool operator < (const TestProxy& obj){
        return test() < obj.test();
    }
    bool operator >= (const TestProxy& obj){
        return test() >= obj.test();
    }
    bool operator > (const TestProxy& obj){
        return test() > obj.test();
    }
    bool operator <= (const TestProxy& obj){
        return test() <= obj.test();
    }

    Test& operator = (Test& test){
        m_ptest = &test;
        return test;
    }
};

Test tp[1000];

TestProxy pt[1000];

#endif

extern "C" JNIEXPORT jstring JNICALL
Java_com_myalgorithm_tab_MainActivity_stringFromJNI(
        JNIEnv* env, jobject /* this */) {
#if TEST6_SEARCH
        int a[] = {1, 1, 3, 4, 5, 6, 6, 6, 3, 3,3};
        search(a,sizeof (a)/sizeof (int));
#endif

#if TEST9_SMARTPOINTER
    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> sp1;
    sp1 = sp;
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "sp.isNull: %d",sp1.isNull());
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "sp.isNull: %d",sp.isNull());
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "sp.isNull: %d",sp1.isNull());
#endif

#if TEST11_EXCEPTION
    try {
        THROW_EXCEPTION(ArithmeticException,"test");
        //throw Exception("test",__FILE__,__LINE__);
    }
    catch(const ArithmeticException& e){
        cout<<"catch(const ArithmeticException& e)"<<endl;
        cout<<e.message()<<endl;
        cout<<e.location()<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "ArithmeticException %s %s",e.message(),e.location());
    }
    catch (const Exception& e) {
        cout<<"catch(const Exception& e)"<<endl;
        cout<<e.message()<<endl;
        cout<<e.location()<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Exception %s %s",e.message(),e.location());
    }

#endif

#if TEST12_TOPOBJECT
    Object* test = new NextTest();
    cout<<"new: "<<test<<endl;
    //....
    delete test;
#endif

#if TEST18_STATICLIST
    StaticList<int,5> list;

    for(int i = 0; i < list.capacity(); i++){
        list.insert(0,i);
    }
    for (int i=0;i<list.length();i++) {
        //cout<<list[i]<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "list: %d",list[i]);
    }
    list[0] *= list[0];
    for (int i=0;i<list.length();i++) {
        //cout<<list[i]<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "list: %d",list[i]);
    }
    try{
        list[5] = 7;
    }
    catch(const Exception& e){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Exception %s %s",e.message(),e.location());
    }

#endif

#if TEST19_DYNAMICLIST
    DynamicList<int> list(5);
    for (int i=0;i<list.capacity();i++) {
        list.insert(0,i);
    }
    for (int i=0;i<list.length();i++) {
        cout<<list[i]<<endl;
    }
    try {
        list[10] = 8;
    } catch (const Exception& e) {
        cout<<e.message()<<endl;
        cout<<e.location()<<endl;
    }

    list.resize(12);
    for (int i=0;i<list.capacity();i++) {
        list.insert(0,i);
    }
    for (int i=0;i<list.length();i++) {
        cout<<list[i]<<endl;
    }
    list[10] = 8;

    cout<<"len: "<<list.length()<<"capaticy: "<<list.capacity()<<endl;
    for (int i=0;i<list.length();i++) {
        cout<<list[i]<<endl;
    }
#endif

#if TEST20_ARRAY
    StaticArray<int,5> s1;
    for (int i=0;i<s1.length();i++) {
        s1[i] = i*i;
    }
    for (int i=0;i<s1.length();i++) {
        //cout<<s1[i]<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "StaticArray: %d",s1[i]);
    }

    DynamicArray<int> s2(6);
    for (int i=0;i<s2.length();i++) {
        s2[i] = i*i;
    }

    for (int i=0;i<s2.length();i++) {
        //cout<<s2[i]<<endl;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "DynamicArray: %d",s2[i]);
    }
#endif

#if TEST22_LINKLIST
    LinkList<int> ll1;
    for(int i=0; i<5; i++) {
        //ll1.insert(i);
        ll1.insert(0, i);
        ll1.set(0, i*i);
    }

    for(int i=0; i<ll1.length(); i++) {
        /*
        int v = 0;
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "LinkList: %d",ll1.get(i,v));
        */
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "LinkList: %d",ll1.get(i));
    }
    ll1.remove(2);
    //ll1.clear();
    // 遍历方式
    for (ll1.move(0); !ll1.end(); ll1.next()) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "ll1: %d",ll1.current());
    }

    ll1.find(5);


    for(int i=0; i<ll1.length(); i++) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "LinkList: %d",ll1.get(i));
    }

//    LinkList<Test> testList;
//    Test t;
//    testList.insert(t);

    Test1 t1(1),t2(2),t3(3),t4(4);
    LinkList<Test1> testList1;
    testList1.insert(t1);
    testList1.insert(t2);
    testList1.insert(t3);
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "testList1: %d ",testList1.find(t4));

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "testList");

#endif

#if TEST22_STATICLINKLIST
    StaticLinkList<int,10> ll1;
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "ll1: %d,%d",ll1.capacity(),ll1.length());
    ll1.insert(5);

    for(int i=0; i<5; i++) {
        ll1.insert(i);
    }
    for (ll1.move(0); !ll1.end(); ll1.next()) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "ll1: %d,%d",ll1.current(),ll1.length());
    }
#endif

#if TEST28_SHAREDPOINTER
    SharePointer<Test> sp0 = new Test();
    SharePointer<Test> sp1 = sp0;
    SharePointer<Test> sp2 = nullptr;

    sp2 = sp1;
    sp0->value = 100;


    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "SharePointer.value: %d",sp0->value);
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "SharePointer.value: %d",sp1->value);
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "SharePointer.value: %d",sp2->value);
    sp1.clear();
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "SharePointer op: %d",(sp1==sp0));
#endif

#if TEST34_STATICSTACK

//    StaticStack<int,8> stack;
//    try {
//        stack.pop();
//    }
//    catch (const Exception& e) {
//        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Exception %s %s",e.message(),e.location());
//    }
//
//    for (int i = 0; i < 8; ++i) {
//        stack.push(i);
//    }
//    while (stack.size()>0){
//        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "stack.top: %d",stack.top());
//        stack.pop();
//    }

    StaticStack<Test,20> stack;
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "stack.size: %d",stack.size());

#endif
#if TEST35_LINKSTACK

    LinkStack<int> stack;
    try {
        stack.pop();
    }
    catch (const Exception& e) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Exception %s %s",e.message(),e.location());
    }

    for (int i = 0; i < 8; ++i) {
        stack.push(i);
    }
    while (stack.size()>0){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "stack.top: %d",stack.top());
        stack.pop();
    }

//    LinkStack<Test> stack;
//    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "stack.size: %d",stack.size());
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "stack.is match: %d",scan("{\"title\":\"json在线解析（简版） -JSON在线解析\",\"json.url\":\"https://www.sojson.com/simple_json.html\",\"keywords\":\"json在线解析\",\"功能\":[\"JSON美化\",\"JSON数据类型显示\",\"JSON数组显示角标\",\"高亮显示\",\"错误提示\",{\"备注\":[\"www.sojson.com\",\"json.la\"]}],\"加入我们\":{\"qq群\":\"259217951\"}}"));
#endif
#if TEST36_STATICQUEUE
    StaticQueue<int,5> queue;
    for (int i = 0; i < 5; ++i) {
        queue.add(i);
    }
    while (queue.length()>0){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "queue: %d",queue.front());

        queue.remove();
    }
#endif
#if TEST36_LINKQUEUE
    LinkQueue<int> queue;
    for (int i = 0; i < 5; ++i) {
        queue.add(i);
    }
    while (queue.length()>0){
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "queue: %d",queue.front());
        queue.remove();
    }
#endif
#if TEST39_HSTRING
    //test_1();

    HString string1 = "ababax";
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s1 %s ",string1.remove(1,2).str());
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s1 %d ",string1.remove(1,2).length());

    HString string2 = "ababax";
    HString string3 = string2 - "ba";
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s1: %s , s2: %s ",string2.str(),string3.str());

    string2 -= "ba";

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s1: %s , s2: %s ",string2.str(),string3.str());

    string2.replace("ba","xyz");

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s1: %s , s2: %s ",string2.str(),string3.str());

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "s2.sub: %s",string2.sub(3,4).str());

#endif

#if TEST44_RECURSION
    //HanoiTower(3,'A','B','C');
//    char ddd[] = "aacdd";
//    permutation(ddd,ddd);

//    Node* list = create_list(1,10);
//    print_list(list);
//    print_list(reverse(list));
//    destory_list(list);
//    Node* list1 = create_list(1,5);
//    Node* list2 = create_list(4,6);
//    Node* list = marge(list1,list2);
//    print_list(list);
//    destory_list(list);

    Node* list1 = create_list(1,5);
    print_list(list1);

    r_print_event(list1);

    destory_list(list1);
#endif

#if TEST46_SORT

    int arry[] = {1,0,5,4,6,7,8,11,3};
    int length = sizeof(arry) / sizeof(int);
    /*
//    Sort::Select(arry,length, true);
//    Sort::Insert(arry,length, false);
//    Sort::Bubble(arry,length, true);
//    Sort::Shell(arry,length, false);
//    Sort::Merge(arry,length, false);
    Sort::Quick(arry,length);

    for (int i = 0; i < length; ++i) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "array: %d ",arry[i]);
    }
*/
    StaticArray<int,9> sa;
    for (int i = 0; i < length; ++i) {
        sa[i] = arry[i];
    }
    Sort::Insert(sa, false);
    for (int i = 0; i < sa.length(); ++i) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "sa: %d ",sa[i]);
    }

#endif

#if TEST50_SORT

    clock_t start=0,end=0;

    for (int i = 0; i < 1000; ++i) {
        tp[i].id = i;
        pt[i] = tp[i];
    }
    start = clock();
    Sort::Bubble(pt,1000, false);
    end = clock();

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "Time: %ld ",(end-start));

#endif

#if TEST52_GTREE
    /*
    GTree<int> t;
    GTreeNode<int> p;
    t.find(0);
    t.find(&p);
     */

    GTree<char> t;
    GTreeNode<char>* node = nullptr;
    t.insert('A', nullptr);

    node = t.find('A');
    t.insert('B', node);
    t.insert('C', node);
    t.insert('D', node);

    node = t.find('B');
    t.insert('E', node);
    t.insert('F', node);

    node = t.find('E');
    t.insert('K', node);
    t.insert('L', node);

    node = t.find('C');
    t.insert('G', node);

    node = t.find('D');
    t.insert('H', node);
    t.insert('I', node);
    t.insert('J', node);

    node = t.find('H');
    t.insert('M', node);
    //t.clear();

    //t.remove('D');

    const char* s = "KLFGMIJ";
//    for (int i = 0; i < 7; ++i) {
//        TreeNode<char>* node = t.find(s[i]);
//        while (node!= nullptr){
//            __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, " %c ",node->value);
//
//            node = node->parent;
//        }
//    }
    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, " count: %d height: %d degre: %d",t.count(),t.height(),t.degree());

    for (t.begin(); !t.end(); t.next()) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "current: %c",t.current());
    }

    SharePointer<Tree<char>> sp = t.remove(t.find('D'));
    for (int i = 0; i < 7; ++i) {
        TreeNode<char>* node = sp->find(s[i]);
        while (node!= nullptr){
            __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, " %c ",node->value);

            node = node->parent;
        }
    }

    __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, " count: %d height: %d degre: %d",t.count(),t.height(),t.degree());

    for (t.begin(); !t.end(); t.next()) {
        __android_log_print(ANDROID_LOG_VERBOSE, LOG_TGA, "current: %c",t.current());
    }


#endif

    string str = "Exception";

    return env->NewStringUTF(str.c_str());
}
