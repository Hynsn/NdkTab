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

// 数组栈，特殊的线性表唯一特性 先进后出。
// 使用原生数组作为存储结构，存在缺点就是，链表构造函数和析构函数初始化时需要频繁执行。
#define TEST34_STATICSTACK 0

// 链式栈，栈非常适用于就近匹配的场合
#define TEST35_LINKSTACK 0

// 数组队列，先进先出，使用原生数组实现容量由模板参数决定，采用循环计数法实现队列的操作
#define TEST36_STATICQUEUE 0

#define TEST36_LINKQUEUE 1

#define TEST39_HSTRING 0

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
    test_1();
#endif
    string str = "Exception";
    return env->NewStringUTF(str.c_str());
}