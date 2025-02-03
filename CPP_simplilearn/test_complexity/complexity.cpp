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

// #include<iostream>
// using namespace std;


// /*
// Insertion Sort Function:

// The insertionSort function takes an array and its size as input.

// It starts with the second element and compares it with the elements before it, moving larger elements one position to the right and inserting the element at its correct position.

// This process is repeated for each element in the array.
// */

// void insertionSort(int arr[], int n){
//     for (int i = 1; i < n; i++){
//         int key = arr[i];
//         int j = i - 1;

//         // Move element fo arr[0.. i-1], that are greater than key,
//         // to one position ahead of their current position 
//         while(j >= 0 && arr[j] > key){
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

// void printArray(int arr[], int n){
//     for (int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr[] = {12, 11, 13, 15, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     insertionSort(arr, n);

//     cout << "Sorted array: ";
//     printArray(arr, n);

//     return 0;
// }

// T.C -> O(n^2)
// S.C -> O(n)








// -------------------- Merge sort -----------------------

// #include<iostream>
// using namespace std;

// // Function to merge two subarrays
// void merge(int arr[], int left, int mid, int right){
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     // Create temporary arrays
//     int L[n1], R[n2];

//     // Copy data to temporary arrays
//     for (int i = 0; i < n1; i++){
//         L[i] = arr[left + i];
//     }

//     for (int j = 0; j < n2; j++){
//         R[j] = arr[mid + 1 + j];
//     }

//     // Merge the temporary arrays back into arr[left..right]
//     int i = 0; // initial index of first subarray
//     int j = 0; // Initial index of second subarray
//     int k = left;  // Initial index of merged subarray

//     while (i < n1 && j < n2){
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of L[], if any
//     while(i < n1){
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of R[], if any
//     while(j < n2){
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
    
// }

// // Function to implement Merge Sort
// void mergeSort(int arr[], int left, int right){
//     if (left < right){
//         int mid = left + (right - left) / 2;

//         // Recursively sort the first and second halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         // Merge the sorted halves
//         merge(arr, left, mid, right);
//     }
// }

// // Functio to print an array
// void printArray(int arr[], int size){
//     for (int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int arr_size = sizeof(arr) / sizeof(arr[0]);  
//     // sizeof(arr) -> 6*4 = 24
//     // sizeof(arr[0]) -> 4
//     // 24 / 4 = 6

//     cout << "Original array: ";
//     printArray(arr, arr_size);

//     mergeSort(arr, 0, arr_size -1);

//     cout << "Sorted array: ";
//     printArray(arr, arr_size);

//     return 0;
// }


// T.C -> O(n long n)
// S.c -> O(n)


/*

Explanation:
Merge Function:

The merge function takes an array and the indices of the left, middle, and right points.

It merges two subarrays (left and right) back into the original array in sorted order.

Merge Sort Function:

The mergeSort function recursively divides the array into two halves and sorts each half.

It then merges the sorted halves using the merge function.

Print Array Function:

The printArray function prints the elements of the array.

Main Function:

The main function initializes an array and calls the mergeSort function to sort the array.

It prints the original and sorted arrays.

Time Complexity:
The time complexity of Merge Sort is O(n log n) in all cases (best, average, and worst).

Space Complexity:
The space complexity of Merge Sort is O(n) due to the temporary arrays used for merging.

*/


















// ++++++++++++++++++ Merge Sort ++++++++++++++++++++++

// #include<iostream>
// using namespace std;

// // Function to swap two elements
// // void swap(int* a, int* b){
// //     int t = *a;
// //     *a = *b;
// //     *b = t;
// // }

// // Function to swap two elements using references
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// // Partition function that places the pivot element at its correct position
// // and places all smaller elements to the left and greater elements to the right
// int partition(int arr[], int low, int high){
//     int pivot = arr[high];
//     int i = (low - 1);

//     for (int j = low; j < high; j++){
//         if (arr[j] < pivot){
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// // QuickSort function that recursively sorts the array
// void quickSort(int arr[], int low, int high){
//     if (low < high){
//         int pi = partition(arr, low, high);

//         // Recursively sort elements befor and after partitioin
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// // Function to print an array
// void printArray(int arr[], int size){
//     for (int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     quickSort(arr, 0, n - 1);

//     cout << "Sorted array: ";
//     printArray(arr, n);

//     return 0;
// }




// T.C -> O(n log n)
// S.C -> O(log n)


/*

Explanation:
Swap Function Using References:

The swap function now takes two integer references as parameters.

It swaps the values using a temporary variable.

Partition Function:

The partition function remains the same, but it calls the updated swap function that uses references.

QuickSort Function:

The quickSort function remains the same.

Print Array Function:

The printArray function remains the same.

Main Function:

The main function initializes an array and calls the quickSort function to sort the array.

It prints the original and sorted arrays.


Time Complexity:
The time complexity of Quick Sort is O(n log n) on average and O(n^2) in the worst case.

Space Complexity:
The space complexity of Quick Sort is O(log n) due to the recursion stack.
 */















// +++++++++++++++++++++ Bubble Sort +++++++++++++++++++++++++++

#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j + 1]){  // greater than for increasing order and less than for decreasing order
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}



// T.C -> O(n^2)
// S.C -> O(n)



/*

Explanation:
Bubble Sort Function:

The bubbleSort function takes an array and its size as input.

It uses nested loops to compare each pair of adjacent elements and swap them if they are in the wrong order.

This process is repeated until the array is sorted.

Print Array Function:

The printArray function prints the elements of the array.

Main Function:

The main function initializes an array and calls the bubbleSort function to sort the array.

It prints the original and sorted arrays.

Time Complexity:
The time complexity of Bubble Sort is O(n^2) in the worst and average cases.

In the best case (when the array is already sorted), the time complexity is O(n).

Space Complexity:
The space complexity of Bubble Sort is O(1) since it sorts the array in place without using any additional memory.

*/