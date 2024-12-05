// #1 C++ program to read array of size n and find the frequency of the given element

/*
# include<iostream>
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
  
  cout << "Enter the element to find its frequency: ";
  cin >> x;

  for(i = 0; i < n; i++){
    if(arr[i] == x){
      count++;
    }
  }
  cout << "Frequency of " << x << " is " << count << endl;
  return 0;
}
*/

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

// #2 C++ program to read array of size n and find the frequency of all element

/*
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
*/


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



// ------------ #3 question ------------------------
// Write a C++ program to find the maximum and minimum element in an array of integers.

/*
#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";

  for(int i=0; i < n; i++){
    cin >> arr[i];
  }

  int max = arr[0];
  int min = arr[0];

  for(int i=1; i < n; i++){
    if(arr[i] > max){
      max = arr[i];
    }
    if(arr[i] < min){
      min = arr[i];
    }
  }

  cout << "Maximum element in the array is: " << max << endl;
  cout << "Minimum element in the array is: " << min << endl;
  return 0;
}
*/

// ++++++++++++++++ output +++++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 6
// Enter the elements of the array: 99
// 2
// 6
// 88
// 44
// 1
// Maximum element in the array is: 99
// Minimum element in the array is: 1
// PS J:\My Drive\DSA-WORDSPACE\c++\session3>



// ------------------- #4 -----------------------
// #4 Write C++ program to find the array type (even, odd or mixed)

#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";
  for(int i=0; i < n; i++){
    cin >> arr[i];
  }

  // ++++++++++++++++ code +++++++++++++++++++
  int count_even = 0;
  int count_odd = 0;
  for(int i=0; i < n; i++){
    if(arr[i] % 2 == 0){
      count_even++;
    }
    else{
      count_odd++;
    }
  }

  // ++++++++++++++++ code +++++++++++++++++++

  if(count_even == n){
    cout << "Array type is: even" << endl;
  }else {
    if(count_odd == n){
      cout << "Array type is: odd" << endl;
      }else{
        cout << "Array type is: mixed" << endl;
    }
  }

  return 0;
}


// ++++++++++++++++ output +++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 5
// Enter the elements of the array: 5
// 5
// 5
// 7
// 7
// Array type is: odd
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 4
// Enter the elements of the array: 2
// 2
// 4
// 4
// Array type is: even
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> g++ .\Array_practice.cpp -o Array_practice  
// PS J:\My Drive\DSA-WORDSPACE\c++\session3> ./Array_practice
// Enter the size of the array: 3
// Enter the elements of the array: 1
// 2
// 3
// Array type is: mixed
// PS J:\My Drive\DSA-WORDSPACE\c++\session3>


