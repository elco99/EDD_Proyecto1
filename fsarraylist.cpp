#include "fsarraylist.h"
#include <stddef.h>
#include <iostream>
using namespace std;

FSArrayList::FSArrayList(int p){
    this->array = new Object*[p];
    this->capacity = p;
}

FSArrayList::~FSArrayList(){   
    for (int i = 0; i < size; ++i)
         delete array[i];
     delete[] array;

}

bool FSArrayList::insert(Object*, int){

}
int FSArrayList::indexOf(Object*)const{

}
Object* FSArrayList::get(unsigned int)const{

}
bool FSArrayList::erase(unsigned){

}

int FSArrayList::prev(int p)const{
    return p-1;
}

int FSArrayList::next(int p)const{
    return p+1;
}

void FSArrayList::reset(){

}
Object* FSArrayList::first()const{

}
Object* FSArrayList::last()const{

}
void FSArrayList::print()const{

}

bool FSArrayList::isFull()const{
    if(size == capacity)
        return true;
    return false;

}

int FSArrayList::getCapacity()const{
    return capacity;
}