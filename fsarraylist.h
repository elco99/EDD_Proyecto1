#ifndef FSARRAYLIST_H
#define FSARRAYLIST_H
#include "tdalist.h"
#include "object.h"

/*
* Esta es la clase Base para la Implementación del TDA Lista
* Cualquier implementación de este TDA deberá ser descendiente de esta clase.
* Todas las operaciones están declaradas, no así definidas, lo cual hace
* que esta clase sea abstracta; y obliga a que las descendientes las definan.
* Nótese que tienen todas las operaciones colocadas en la especificación
* vista en clase.
*/

class FSArrayList : public TDAList{
  protected:
    Object** array;
    unsigned int capacity;

  public:
    FSArrayList(int);
    virtual ~FSArrayList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned int)const ;
    virtual bool erase(unsigned) ;
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