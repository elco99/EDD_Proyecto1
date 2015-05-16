#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "tdalist.h"
#include "linkedlist.h"
#include "fsarraylist.h"
#include "fscursorlist.h"
#include "integer.h"
#include <ctime>
#include <sstream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std; 

int main(int argc, char *argv[]){
  ofstream file1("FSALInsert.txt");
  ofstream file2("FSALget.txt");
  ofstream file3("FSALIndex.txt");
  //ofstream file4("FSALFirst.txt");
  //ofstream file5("FSALLast.txt");
  //ofstream file6("FSALRemove.txt");
  //ofstream file7("DLLInsert.txt");
  //ofstream file8("DLLget.txt");
  //ofstream file9("DLLindex.txt");
  //ofstream file10("DLLfirst.txt");
  //ofstream file11("DLLlast.txt");
  //ofstream file12("DLLremove.txt");
  //ofstream file13("ClInsert.txt");
  //ofstream file14("ClGet.txt");
  //ofstream file15("ClIndex.txt");
  //ofstream file16("CLFirst.txt");
  //ofstream file17("CLLast.txt");
  //ofstream file18("ClRemove.txt");
  //*****************************************************************************************************************
  //tanto estas variables como sus respectivos metodos fueron puestos en comentarios ya que al intentar             *
  //correr mas de 3 estos al mismo tiempo causaba que el programa se trabara, asi que para obtener los datos los    *
  //corrimos de esta manera                                                                                         *
  //*****************************************************************************************************************
  double ExecutionTime;
  time_t start,end;
  srand(time(0));
  TDAList* ListaArrayList = new FSArrayList(1000);
  TDAList* ListaLinkedList = new LinkedList();
  TDAList* ListaCursorList = new FSCursorList(1000);
  int posiciones[1000];
  bool entro = false;
  for (int z = 0; z< 1000; z++){
    int random = rand()%1000;
    for (int j = 0; j < 1000; j++){
      if(random == posiciones[j]){
        entro = true;
        break;
      }    
    } 
    if(!entro)
      posiciones[z] = random; 
    else    
      z--; 
    entro = false;
  }  
  //****************************FSArrayList************************************  
  for (int i = 0; i <1000; i++){ 
    start=clock(); 
    ListaArrayList->insert(new Integer(i),posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file1.is_open()){
      file1<<ExecutionTime<<"\n";
    }
  }
  file1.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaArrayList->get(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file2.is_open())
      file2<<ExecutionTime<<"\n";
  }
  file2.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaArrayList->indexOf(new Integer(i));
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file3.is_open())
      file3<<ExecutionTime<<"\n";
  }
  file3.close();/*
  for (int j = 0; j <1000; j++){ 
    start=clock(); 
    ListaArrayList->first();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file4.is_open())
      file4<<ExecutionTime<<"\n";
  }
  file4.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaArrayList->last();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file5.is_open())
      file5<<ExecutionTime<<"\n";
  }
  file5.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaArrayList->erase(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    if(file6.is_open())
      file6<<ExecutionTime<<"\n";
  }
  file6.close();

  //**************************Linked List********************************
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->insert(new Integer(i),posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file7<<ExecutionTime<<"\n";
  }  
  file7.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->get(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file8<<ExecutionTime<<"\n";
  }
  file8.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->indexOf(new Integer(i));
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file9<<ExecutionTime<<"\n";
  }
  file9.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->first();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file10<<ExecutionTime<<"\n";
  }
  file10.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->last();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file11<<ExecutionTime<<"\n";
  }
  file11.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaLinkedList->erase(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file12<<ExecutionTime<<"\n";
  }
  file12.close();

    //**************************Cursor List********************************
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->insert(new Integer(i),posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file13<<ExecutionTime<<"\n";
  }
  file13.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->get(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file14<<ExecutionTime<<"\n";
  }  
  file14.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->indexOf(new Integer(i));
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file15<<ExecutionTime<<"\n";
  }  
  file15.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->first();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file16<<ExecutionTime<<"\n";
  }
  file16.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->last();
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file17<<ExecutionTime<<"\n";
  }
  file17.close();
  for (int i = 0; i <1000; ++i){ 
    start=clock(); 
    ListaCursorList->erase(posiciones[i]);
    end=clock();
    ExecutionTime=(double)(end-start)/(double)CLOCKS_PER_SEC;
    file18<<ExecutionTime<<"\n";
  }
  file18.close();*/
  return 0;
}