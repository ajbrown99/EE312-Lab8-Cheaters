
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#ifndef _HASH_H
#define _HASH_H

using namespace std;

class hash{

private:

   static const int SIZE = 1000001;

   struct linked_list{
       int data;
       linked_list* next; 
   };
   
   linked_list* table[SIZE];

public:

   hash();

   void hashing(vector<string> x,int size,int index);

   int getSize();

   vector<string> traverse(vector<string>files,int size,int min);
   
};

#endif
