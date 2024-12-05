// C++ program to read array of size n and find the frequency of the given element

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



