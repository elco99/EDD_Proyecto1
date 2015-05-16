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
  //ofstream file2("FSALget.txt");
  //ofstream file3("FSALIndex.txt");
  //ofstream file4("FSALFirst.txt");
  //ofstream file5("FSALLast.txt");
  //ofstream file6("FSALRemove.txt");
  //ofstream file7("DLinsert.txt");
  //ofstream file8("DLremove.txt");
  //ofstream file9("DLget.txt");
  //ofstream file10("DLindex.txt");
  //ofstream file11("DLfirst.txt");
  //ofstream file12("DLlast.txt");
  //ofstream file13("ClInsert.txt");
  //ofstream file14("Clremove.txt");
  //ofstream file15("Clget.txt");
  //ofstream file16("ClIndex.txt");
  //ofstream file17("CLfirst.txt");
  //ofstream file18("CLlast.txt");
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
    if(!entro){ 
      posiciones[z] = random; 
    }else{      
      z--; 
    }
    entro = false;
  }

  
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
  return 0;
}