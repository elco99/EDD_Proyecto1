#include "fscursorlist.h"
#include <iostream>
using namespace std;


FSCursorList::FSCursorList(int p){
    this->capacity = p;
    head = -1;
    size =0;
    rows = new Row[p];
    if(!rows)
        throw "No hay memoria";
    for (int i = 0; i < capacity; ++i){
        rows[i].prev = -1;
        rows[i].next = -1;
        rows[i].data = NULL;

    }
}
FSCursorList::~FSCursorList(){
    int temp = head;
    for (int i = 0; i < size; ++i)
    {
        delete rows[temp].data;
        temp = rows[temp].next;
    }
    delete[] rows;

}
bool FSCursorList::insert(Object* E, int p){
    if(p < 0 || p >= capacity)
        return false;
    if(isFull())
        return false;
    int neo = nextAvail();
    cout<<neo<<endl;
    if(head == -1 && p == 0){
        head = neo;
        rows[head].prev = -1;
        rows[head].next =-1;
        rows[head].data = E;
    }else if(p == 0 && head != -1){
        rows[neo].prev = -1;
        rows[neo].next = head;
        rows[head].prev = neo;
        head = neo;
        rows[neo].data = E;
    }else{
        int tmp = head;
        for (int i = 0; i < p-1; ++i)
            tmp = rows[tmp].next;
        rows[neo].prev = tmp;
        rows[neo].next = rows[tmp].next;
        if(p < size)
            rows[rows[neo].prev].next = neo;
        rows[neo].data = E;
    }
    size++;
    return true;

}

int FSCursorList::nextAvail(){
    for (int i = 0; i < capacity; ++i)
       if(rows[i].next == -1 && rows[i].prev == -1 && rows[i].data == NULL)
            return i;
}
int FSCursorList::indexOf(Object*E)const{
    int temp = head;
     for(int i = 0; i < size; i++){        
        if( rows[temp].data->equals(E))
            return i;
        temp = rows[temp].next;
    }
    return -1;
}
Object* FSCursorList::get(unsigned p)const{
    if(size == 0)
        return NULL;
    int temp = head;
    for (int i = 0; i < p; ++i){
        temp = rows[temp].next;
    }
    return rows[temp].data;
}
bool FSCursorList::erase(unsigned p){
    if(p < 0 || p>= size)
        return false;
    int neo, tmp;
    Object* ret;
    if(p ==0){
        tmp = head;
        ret = rows[head].data;
        head = rows[head].next;
        rows[tmp].next = -1;
        rows[tmp].prev = -1;
        rows[tmp].data = NULL;
        rows[head].prev = -1;
    }else{
        tmp = head;
        for(int i =0 ; i < p-1; i++)
            tmp = rows[tmp].next;
        neo = rows[tmp].next;
        ret = rows[neo].data;
        rows[tmp].next = rows[neo].next;
        rows[rows[neo].next].prev = tmp;
    }
    size--;
    return true;
}
int FSCursorList::prev(int p) const{
        return 0;
}
int FSCursorList::next(int p) const{
        return 0;
}
void FSCursorList::reset(){
}
Object* FSCursorList::first()const{
    if(size == 0)
        return NULL;
    return rows[head].data;
}
Object* FSCursorList::last()const{ 
    int temp = head,cont = 0;
    do{
        temp = rows[temp].next;
        cont++;
    }while(cont<size);
    return rows[temp].data;
}
void FSCursorList::print()const{
    int temp = head,cont = 0;
    do{
        rows[temp].data->print();
        temp = rows[temp].next;
        cont++;
    }while(cont<size);
}
bool FSCursorList::isFull()const{
    if(size == capacity)
        return true;
    return false;
}
int FSCursorList::getCapacity()const{
        return 0;
}