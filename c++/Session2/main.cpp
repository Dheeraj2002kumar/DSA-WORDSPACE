#include<iostream>
using namespace std;

int main(){
  int n=10, k=5;

  int number;

  cout << "Enter the number of candies you want ";
  cin >> number;

  if(number >= 1 && number <= 5){
    cout << "Number of candies sold: " << number;
    cout << "Number of candies left in the jar: " << n-number;
  } else{
    cout << "Invalid number of candies";
    cout << "No. of candies left in the jar" << n;
  }

  return 0;
}

// ++++++++++++ output ++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\Session2> g++ main.cpp -o main
// PS J:\My Drive\DSA-WORDSPACE\c++\Session2> ./main
// Enter the number of candies you want 5
// Number of candies sold: 5Number of candies left in the jar: 5