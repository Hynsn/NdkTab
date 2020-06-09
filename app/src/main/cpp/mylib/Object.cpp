#include "Object.h"

#include <cstdlib>

#include <iostream>

using namespace std;

namespace HynLib {

void* Object::operator new (size_t size) throw(){
   //cout<<"malloc size: "<<size<<endl;
   return malloc(size);
}
void Object::operator delete (void* p){
    //cout<<"delete: "<<p<<endl;
    free(p);
}

void* Object::operator new[] (size_t size) throw(){
    return malloc(size);
}
void Object::operator delete[] (void* p){
    free(p);
}

Object::~Object(){ }

}
