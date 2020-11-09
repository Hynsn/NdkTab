#ifndef SORT_H
#define SORT_H

#include "Object.h"
#include "Array.h"

namespace HynLib{
class Sort : public Object{
private:
    Sort();
    Sort(const Sort& s);
    Sort& operator = (const Sort&);
    template <typename T>
    static void Swap(T& a,T& b){
        T c(a);
        a = b;
        b = c;
    }

    template <typename T>
    static void Merge(T src[],T helper[],int begin,int mid,int end,bool min2max = true){
        int i = begin;
        int j = mid + 1;
        int k = begin;

        while ((i<=mid) && (j<=end)){
            if(min2max ? src[i]<src[j] : src[i]>src[j]){ // 左边
                helper[k++] = src[i++];
            }
            else{ // 右边
                helper[k++] = src[j++];
            }
        }
        // 拷贝左边未比较部分
        while (i<=mid){
            helper[k++] = src[i++];
        }
        // 拷贝右边未比较部分
        while (j<=end){
            helper[k++] = src[j++];
        }
        for (i = begin; i <= end; i++) {
            src[i] = helper[i];
        }
    }
    template <typename T>
    static void Merge(T src[],T helper[],int begin,int end,bool min2max = true){
        if(begin < end){
            int mid = (begin+end) / 2;
            Merge(src,helper,begin,mid,min2max);
            Merge(src,helper,mid+1,end,min2max);
            Merge(src,helper,begin,mid,end,min2max); // 真正的归并
        }
    }

    // 基准划分函数
    template <typename T>
    static int Partition(T arry[],int begin,int end,bool min2max = true){
        T pv = arry[begin];
        while (begin < end){
            while((begin<end) && (min2max? (arry[end] > pv) : (arry[end] < pv))){
                end--;
            }
            Swap(arry[begin],arry[end]);
            while((begin<end) && (min2max? (arry[begin] <= pv) : (arry[begin] >= pv))){
                begin++;
            }
            Swap(arry[begin],arry[end]);
        }
        arry[begin] = pv;
        return begin;
    }
    template <typename T>
    static void Quick(T arry[],int begin,int end,bool min2max = true){
        if(begin < end){
            int pivot = Partition(arry,begin,end,min2max);

            Quick(arry,begin,pivot-1,min2max);
            Quick(arry,pivot+1,end,min2max);
        }
    }

public:
    template <typename T>
    static void Select(T arry[],int len, bool min2max= true){
        for (int i = 0; i < len; ++i) {
            // 查找最小值
            int min = i;
            for (int j = i+1; j < len; j++) {
                if(min2max ? (arry[min] > arry[j]) : (arry[min] < arry[j])){
                    min = j;
                }
            }
            // 交换
            if(min!=i) Swap(arry[i],arry[min]);
        }
    }
    template <typename T>
    static void Insert(T arry[],int len, bool min2max= true){
        for (int i = 1; i < len; ++i) {
            int k = i;
            T e = arry[i];

            // 比较移动
            for (int j =i-1 ; (j >= 0) && (min2max ? (e < arry[j]) : e > arry[j]); j--) {
                arry[j+1] = arry[j];
                k = j;
            }
            // 赋值
            if(k!=i) arry[k] = e;
        }
    }

    template <typename T>
    static void Bubble(T arry[],int len, bool min2max= true){
        bool exchange = true;

        for (int i = 0; (i < len) && exchange; i++) {
            exchange = false;
            for (int j = len-1; j > i; j--) {
                if(min2max ? (arry[j]<arry[j-1]) : (arry[j]>arry[j-1])){
                    Swap(arry[j],arry[j-1]);
                    exchange = true;
                }
            }
        }
    }
    template <typename T>
    static void Shell(T arry[],int len, bool min2max= true){
        int d = len;
        bool exchange = true;
        do{
            d = d / 3+1; // 实践证明

//            for (int i = d; i < len; i+=d) {
//                int k = i;
//                T e = arry[i];
//                // 比较移动
//                for (int j = i-d ; (j >= 0) && (min2max ? (e < arry[j]) : e > arry[j]); j-=d) {
//                    arry[j+d] = arry[j];
//                    k = j;
//                }
//                // 赋值
//                if(k!=i) arry[k] = e;
//            }
            for (int i = 0; i < len && exchange; i+=d) {
                exchange = false;
                for (int j = len-1; j > i; j-=d) {
                    if(min2max ? (arry[j]<arry[j-1]) : (arry[j]>arry[j-1-d])){
                        Swap(arry[j],arry[j-1]);
                        exchange = true;
                    }
                }
            }
        } while(d>1);
    }

    template <typename T>
    static void Merge(T arry[],int len, bool min2max= true){
        T* helper = new T[len];

        if(helper!=NULL){
            Merge(arry,helper,0,len-1,min2max);
        }

        delete[] helper;
    }

    template <typename T>
    static void Quick(T arry[],int len, bool min2max= true){
        Quick(arry,0,len-1,min2max);
    }
    template <typename T>
    static void Select(Array<T>& array, bool min2max= true){
        Select(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Insert(Array<T>& array, bool min2max= true){
        Insert(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Bubble(Array<T>& array, bool min2max= true){
        Bubble(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Shell(Array<T>& array, bool min2max= true){
        Shell(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Merge(Array<T>& array, bool min2max= true){
        Merge(array.array(),array.length(),min2max);
    }
    template <typename T>
    static void Quick(Array<T>& array, bool min2max= true){
        Quick(array.array(),array.length(),min2max);
    }
};

}

#endif //SORT_H
