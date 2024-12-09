// c++ program to find smallest and largest element in array

/*
#include<iostream>
using namespace std;

int main(){
    int a[10], i, n, large, small;

    cout << "\nEnter the size of array ";
    cin >> n;

    cout << "\nEnter the element of array ";
    for(i = 0; i < n; i++){
        cin >> a[i];
    }

    large = small = a[0];
    for(i = 1; i < n; i++){
        if(a[i] > large){
            large = a[i];
        }
        else if(a[i] < small){
            small = a[i];
        }
    }

    cout << "\nThe smallest element is = " << small;
    cout << "\nThe largest element is = " << large;
    return 0;
}
*/

// ++++++++++++ output ++++++++++++++++++++

// PS J:\My Drive\DSA-WORDSPACE\c++\Session6> g++ practice.cpp -o practice
// PS J:\My Drive\DSA-WORDSPACE\c++\Session6> ./practice

// Enter the size of array 5

// Enter the element of array 3
// 9
// 88
// 5
// -1

// The smallest element is = -1
// The largest element is = 88



// --------------------------------------------------------

// c++ program to find sum of element in array

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "\nEnter the size of array ";
    cin >> n;

    int arr[n];
    int i, sum = 0;

    cout << "\nEnter the elements of array ";
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(i = 0; i < n; i++){
        sum += arr[i];
    }

    cout << "\nThe sum of elements is = " << sum; 
    return 0;
}