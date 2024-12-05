#include<iostream>
using namespace std;

int main(){
  int a[5] = {6,9,1,5,3};  // Direct declaration and initialisation
  cout << "Elements are: \n";
  
  for(int i=0; i<5; i++){   // iterate all the elements
    cout << "a[" << i << "]= " << a[i] << "\n";  // access through index
  }

  return 0;
}

// ++++++++++++ output +++++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ Array.cpp -o Array
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array
// Elements are:
// a[0]= 6
// a[1]= 9
// a[2]= 1
// a[3]= 5
// a[4]= 3
// PS J:\My Drive\DSA-WORDSPACE\c++\session3>