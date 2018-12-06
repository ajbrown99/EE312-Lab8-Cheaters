#include "hash.h"

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>

using namespace std;

hash::hash(){

  for(int i = 0; i < SIZE; i++){
      table[i] = NULL;
  }  
}

int hash::getSize(){

   return SIZE;

}

void hash::hashing(vector<string> x,int size,int index){

  int sum = 0;
  int primeMulti = 11;
  int exponent = 1;
  for(int i = 0; i < x.size();i++){
     for(int j = 0; j < x[i].size();j++){
     sum += (exponent * x[i][j]);
     exponent = exponent * primeMulti;
   }        
 }
 
  sum =(sum%size+size)% size;
 // cout << sum << endl;

  linked_list *node = new linked_list; 
  node->next = NULL;
  node->data = index;
  if(table[sum] == NULL){
    table[sum] = node;
 }
  else{
    node->next = table[sum];
    table[sum] = node;
  
 }  

}

vector<string>hash:: traverse(vector<string>files,int size,int min){

   vector<string> answer;
   int *matchTable[files.size()];
   for(int i = 0; i < files.size();i++){
      
      matchTable[i] = new int[files.size()];
   }   

   for(int i = 0; i < files.size();i++){
     
      for(int j = 0; j < files.size();j++){

         matchTable[i][j] = 0;
   }
 }

   
   linked_list *ptr;
   linked_list *p;
   for(int i = 0; i < size; i++){
      
      if(table[i] != NULL){
         ptr = table[i];
         p = ptr->next;
      
         while(p != NULL){

           matchTable[ptr->data][p->data]++;
           p = p->next;
         }
      }
 
  }

 /* for(int i = 0; i < files.size();i++){
     for(int j = 0; j < files.size();j++){

        cout << matchTable[i][j] << " ";     
  }
  cout << endl;
}
*/
   vector<int>sortNum;
   for(int i = 0; i < files.size();i++){
      for(int j = 0; j < files.size();j++){

         if(matchTable[i][j] > min){
           sortNum.push_back(matchTable[i][j]);
      }
   }
}

   sort(sortNum.begin(),sortNum.end());
   reverse(sortNum.begin(),sortNum.end());
   
   vector<int>::iterator find = sortNum.begin();
 
   while(find != sortNum.end()){

     for(int i = 0; i < files.size(); i++){

         for(int j = 0; j < files.size(); j++){

            if(matchTable[i][j] == *find){
            
              string num;
              stringstream ss;
              ss << matchTable[i][j];
              num = ss.str();

              string print = num  + ":" + files[i] + "," + files[j];
              answer.push_back(print);
          }
         
        }
     }
     find++;
  }
//sort(answer.begin(),answer.end());
 //reverse(answer.begin(),answer.end());
 return answer;
}
