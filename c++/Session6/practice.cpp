// c++ program to find smallest and largest element in array

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