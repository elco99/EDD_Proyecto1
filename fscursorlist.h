#ifndef FSCURSORLIST_H
#define FSCURSORLIST_H
#include "object.h"
#include "tdalist.h"
class FSCursorList : public TDAList{
    struct Row{
        int next,prev;
        Object* data;
    };
    int head,capacity;
    Row* rows;
  public:
    FSCursorList(int);
    virtual ~FSCursorList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    int nextAvail();
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
};

#endif
