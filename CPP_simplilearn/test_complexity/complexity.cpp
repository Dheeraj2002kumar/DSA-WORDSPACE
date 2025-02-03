// Evaluate Time complexity

#include<iostream>
using namespace std;

void printFibonacci(int n){
    int a = 0, b = 1, next;
    cout << "Fibonacci sequence: " << a << " " << b << " ";

    for (int i = 2; i < n; i++){
        next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the number of term: ";
    cin >> n;
    printFibonacci(n);
    return 0;
}

// T.C -> O(n)
// S.C -> O(1)