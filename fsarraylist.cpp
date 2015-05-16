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

bool FSArrayList::insert(Object* E, int p){
    if(p < 0 || p >= capacity)
        return false;
    else {
        if(p >=size ){
            array[size] = E;
            size++;
        }else{
            for (int i = size; i > p; i--){
                array[i] = array[i-1];
            }
            array[p] = E;
            size++;
        }
    }
    return true;

}
int FSArrayList::indexOf(Object* E)const{
    for(int i = 0; i < size; i++)
        if( array[i]->equals(E))
            return i;
    return -1;

}
Object* FSArrayList::get(unsigned int p)const{
    if(size == 0)
        return NULL;
    if(p<0 || p >=size)
        return NULL;
   return array[p];
}

bool FSArrayList::erase(unsigned p){
    Object* temp;
    if(p < 0 || p >= size )
        return false;
    else{
        temp = array[p];
        for (int i = p; i < size; ++i){
            array[p] = array[p+1];
        }
        size--;
    }
    return true;
}

int FSArrayList::prev(int p)const{
    return p-1;
}

int FSArrayList::next(int p)const{
    return p+1;
}

void FSArrayList::reset(){
    for (int i = 0; i < size; ++i){
        delete array[i];
    }
    delete[] array;
    size = 0;
}
Object* FSArrayList::first()const{
    if(size == 0)
        return NULL;    
    return array[0];

}
Object* FSArrayList::last()const{    
    if(size == 0)
        return NULL;
    return array[size-1];

}
void FSArrayList::print()const{   
    for (int i = 0; i < size; ++i){
        array[i]->print();
    }
}

bool FSArrayList::isFull()const{
    if(size == capacity)
        return true;
    return false;

}

int FSArrayList::getCapacity()const{
    return capacity;
}