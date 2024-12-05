// C++ program to read array of size n and find the frequency of the given element

// # include<iostream>
// using namespace std;

// int main(){
//   int n, i, x, count = 0;
//   cout << "Enter the size of the array: ";
//   cin >> n;
  
//   int arr[n];
//   cout << "Enter the elements of the array: ";
  
//   for(i = 0; i < n; i++){
//     cin >> arr[i];
//   }
  
//   cout << "Enter the element to find its frequency: ";
//   cin >> x;

//   for(i = 0; i < n; i++){
//     if(arr[i] == x){
//       count++;
//     }
//   }
//   cout << "Frequency of " << x << " is " << count << endl;
//   return 0;
// }


// +++++++++++++ outptu ++++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice  
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice    
// Enter the size of the array: 5
// Enter the elements of the array: 1
// 22
// 33
// 33
// 33
// Enter the element to find its frequency: 33
// Frequency of 33 is 3
// PS J:\My Drive\DSA-WORDSPACE\c++\session3>





// -----------------------------------------------

// C++ program to read array of size n and find the frequency of all element

#include<iostream>
using namespace std;

int main(){
  int n, i, x, count = 0;
  cout << "Enter the size of the array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of the array: ";
  for(i = 0; i < n; i++){
    cin >> arr[i];
  }
  // find all the element frequency
  for(i = 0; i < n; i++){
    count = 0;
    for(int j = 0; j < n; j++){
      if(arr[i] == arr[j]){
        count++;
      }
    }
    cout << arr[i] << " ";
    cout << "Frequency of " << arr[i] << " is " << count << endl;
  }
  return 0;
}



// +++++++++++++ output ++++++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 9
// Enter the elements of the array: 11
// 1
// 11
// 55
// 55
// 55
// 9
// 11
// 1
// 11 Frequency of 11 is 3
// 1 Frequency of 1 is 2
// 11 Frequency of 11 is 3
// 55 Frequency of 55 is 3
// 55 Frequency of 55 is 3
// 55 Frequency of 55 is 3
// 9 Frequency of 9 is 1
// 11 Frequency of 11 is 3
// 1 Frequency of 1 is 2
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 9
// Enter the elements of the array: 1
// 1
// 9
// 9
// 5
// 9
// 0
// 3
// 0
// 1 Frequency of 1 is 2
// 1 Frequency of 1 is 2
// 9 Frequency of 9 is 3
// 9 Frequency of 9 is 3
// 5 Frequency of 5 is 1
// 9 Frequency of 9 is 3
// 0 Frequency of 0 is 2
// 3 Frequency of 3 is 1
// 0 Frequency of 0 is 2
// PS J:\My Drive\DSA-WORDSPACE\c++\session3>