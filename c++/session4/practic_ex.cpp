// c++ program to find the array size

/*
#include<iostream>
using namespace std;

int main(){
  int arr[10]; // declare an array of size 10

  // int size = sizeof(arr)/sizeof(arr[0]); // find the size of the array

  int size = sizeof(arr)/sizeof(int);
  cout<<"Size of the array is: "<<size<<endl;
  return 0;
}
*/


// ++++++++++++ output ++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\session4> g++ practic_ex.cpp -o practic_ex
// PS J:\My Drive\DSA-WORDSPACE\c++\session4> ./practic_ex
// Size of the array is: 10
// PS J:\My Drive\DSA-WORDSPACE\c++\session4>



// ---------------------------------

// #2. Write program to check if two arrays are the same or not. [Asked in: Amazon, goldman Sachs]?
#include <iostream>
#include <algorithm>
#include <vector>

bool areArraysEqual(std::vector<int>& arr1, std::vector<int>& arr2) {
    // Step 1: Check if lengths are equal
    if (arr1.size() != arr2.size()) {
        return false;
    }

    // Step 2: Sort both arrays
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    // Step 3: Compare elements
    for (size_t i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> array1 = {1, 2, 3, 4};
    std::vector<int> array2 = {4, 3, 2, 1};

    if (areArraysEqual(array1, array2)) {
        std::cout << "Arrays are equal." << std::endl;
    } else {
        std::cout << "Arrays are not equal." << std::endl;
    }

    return 0;
}