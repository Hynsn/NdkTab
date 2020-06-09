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
#define TEST6_SEARCH    1
// 智能指针
#define TEST9_SMARTPOINTER  1
// 异常
#define TEST11_EXCEPTION  1
// 顶层父类
#define TEST12_TOPOBJECT  1
/*
1、对于线性存储类型不适合使用类类型的对象来作为元素，如果为类的插入操作非常耗时，涉及包含String的对象还涉及到strcpy操作、对象拷贝所以非常耗时
2、对于容器类型的类，可以考虑禁用拷贝构造和赋值操作
3、线性表必须先插入元素，才能使用[]操作符访问元素，因为本质不同所以不能替代数组来使用
*/
// 线性表的顺序存储
#define TEST18_STATICLIST  1
#define TEST19_DYNAMICLIST  0
// 静态数组
#define TEST20_ARRAY  1

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
    std::string str = "Exception";
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
// 单链表

    return env->NewStringUTF(str.c_str());
}
