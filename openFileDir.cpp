#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "hash.h"

using namespace std;



/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc,char*argv[])
{
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

          

   /* for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
    }
*/
    

 /*   string name = string(files[2]);
    ifstream myFile("sm_doc_set/");
    if(myFile.is_open()){
       cout << "open" << endl;
    }
    else{
       cout << "Error" << endl;
    }
    return 0;
*/

    files.erase(files.begin());
    files.erase(files.begin());

   /* for(int i = 0; i < files.size();i++){

       cout << i << files[i] << endl;

    }
*/

    hash *h = new hash();
    
    int table_size = h->getSize();
   // cout << table_size << endl;    

    ifstream myFile;
    for(int i = 0; i < files.size(); i++){
      string name = argv[1] + files[i];  //CHANGE TO ARGV[1] at the end
     //cout << name.c_str() << endl << endl;

      myFile.open(name.c_str());

      string newstring;
      int n = atoi(argv[2]); //CHANGE TO ATOI(ARGV[2]) at the end
      vector<string>result;
       for(int j = 0; j < n; j++){
         myFile >> newstring;
         result.push_back(newstring);
     }
         while(myFile >> newstring){
          
         /* vector<string>::iterator iter;
          for(iter = result.begin();iter != result.end();iter++){

             cout << *iter << " ";    

          }
*/
          
          h->hashing(result,table_size,i);
         // cout << "Hashing is done" << endl;         
 

  
	  result.erase(result.begin());
         //cout << endl;
          result.push_back(newstring);
     }
     /* vector<string>::iterator iter2;
      for(iter2 = result.begin(); iter2 != result.end();iter2++){
         
            cout << *iter2 << " ";
     }
*/
     // cout << endl;	 
      myFile.close(); 
   }

   vector<string> finalResult = h->traverse(files,table_size,atoi(argv[3]));
  // cout << "test" << endl;

   vector<string>::iterator finalIter;
   for(finalIter = finalResult.begin();finalIter!=finalResult.end();finalIter++){
        
      cout << (*finalIter) << endl;

    }
}
