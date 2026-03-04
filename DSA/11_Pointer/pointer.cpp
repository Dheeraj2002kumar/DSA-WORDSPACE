#include<iostream>
using namespace std;

// void swap(int *m, int *n){
//     cout << "Within function before swap The value of m=" << *m << "The value of n=" << *n << endl;
    
//     int temp = *m;
//     *m = *n;
//     *n = temp;
    
//     cout << "Withing function after swap The value of m=" << *m << "The value of n=" << *n << endl;
    
// }

void swapAddress(int m, int n){
    cout << "Within function before swap The value of =" << m << "The value of n=" << n << endl;
    
    int temp = m;
    m = n;
    n = temp;
    
    cout << "Withing function after swap The value of m=" << m << "The value of n=" << n << endl;
    
}

int main(){
    int x = 10;
    int y = 20;

    cout << "Value of x=" << x << "value of y=" << y << endl;

    // swap(&x, &y);
    swapAddress(x, y);

    cout << "The value of x=" << x << "The value of x=" << x << endl;

}