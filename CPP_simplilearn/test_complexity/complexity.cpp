// Evaluate Time complexity

// #include<iostream>
// using namespace std;

// void printFibonacci(int n){
//     int a = 0, b = 1, next;
//     cout << "Fibonacci sequence: " << a << " " << b << " ";

//     for (int i = 2; i < n; i++){
//         next = a + b;
//         cout << next << " ";
//         a = b;
//         b = next;
//     }
//     cout << endl;
// }

// int main(){
//     int n;
//     cout << "Enter the number of term: ";
//     cin >> n;
//     printFibonacci(n);
//     return 0;
// }

// T.C -> O(n)
// S.C -> O(1)



// ---------------------------------------------------------------

// Time complexity of Algorithms





// --------------- Insertion Sort ---------------------------

#include<iostream>
using namespace std;


/*
Insertion Sort Function:

The insertionSort function takes an array and its size as input.

It starts with the second element and compares it with the elements before it, moving larger elements one position to the right and inserting the element at its correct position.

This process is repeated for each element in the array.
*/

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        // Move element fo arr[0.. i-1], that are greater than key,
        // to one position ahead of their current position 
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {12, 11, 13, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

// T.C -> O(n^2)
// S.C -> O(n)