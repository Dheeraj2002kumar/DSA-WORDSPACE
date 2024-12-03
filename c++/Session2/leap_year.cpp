// program for leap year...
#include<iostream>
using namespace std;

int main(){
  int year;
  cout << "Enter year value to check ";
  cin >> year;

  if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0)){
    cout << year << " is a leap year";
  } else {
    cout << year << " is not a leap year";
  }

  return 0;
}


// +++++++++++++++++ output +++++++++++++++++++++
// PS J:\My Drive\DSA-WORDSPACE\c++\Session2> g++ .\leap_year.cpp -o leap_year
// PS J:\My Drive\DSA-WORDSPACE\c++\Session2> ./leap_year
// Enter year value to check 2016
// 2016 is a leap year
// PS J:\My Drive\DSA-WORDSPACE\c++\Session2>