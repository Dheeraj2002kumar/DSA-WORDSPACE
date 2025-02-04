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


















// ++++++++++++++++++ Quick Sort ++++++++++++++++++++++

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

// #include <iostream>
// using namespace std;

// // Function to perform Bubble Sort
// void bubbleSort(int arr[], int n){
//     for (int i = 0; i < n-1; i++){
//         for (int j = 0; j < n-i-1; j++){
//             if (arr[j] > arr[j + 1]){  // greater than for increasing order and less than for decreasing order
//                 // Swap arr[j] and arr[j + 1]
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
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
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     bubbleSort(arr, n);

//     cout << "Sorted array: ";
//     printArray(arr, n);

//     return 0;
// }



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















// +++++++++++++++++++ Selection Sort +++++++++++++++++++++++
// Search through an array and keep track of the minimum value during each iteration. At the end of each iteration, we swap variables.

// Quadratic time O(n^2)
// Small data set = okay
// Large data set = Bad

// #include<iostream>
// using namespace std;
// #include <algorithm>

// // Function to perform Selection Sort
// void selectionSort(int arr[], int n){
//     for (int i = 0; i < n-1; i++){
//         int minIndex = i;

//         // Find the minimum element in the unsorted part of the array
//         for (int j = i+1; j < n; j++){
//             if (arr[j] < arr[minIndex]){
//                 minIndex = j;
//             }
//         }

//         // Swap the found minimum element with the first element
//         int temp = arr[minIndex];
//         arr[minIndex] = arr[i];
//         arr[i] = temp;
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
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, n);

//     selectionSort(arr, n);

//     cout << "Sorted array: ";
//     printArray(arr, n);

//     return 0;
// }



// T.C -> O(n^2)
// S.C -> O(1)

/*

Explanation:
Selection Sort Function:

The selectionSort function takes an array and its size as input.

It iterates through the array and for each position, it finds the minimum element in the unsorted part of the array.

It then swaps the found minimum element with the first element of the unsorted part.

This process is repeated for all positions, gradually sorting the array.

Print Array Function:

The printArray function prints the elements of the array.

Main Function:

The main function initializes an array and calls the selectionSort function to sort the array.

It prints the original and sorted arrays.

Time Complexity:
The time complexity of Selection Sort is O(n^2) in all cases (best, average, and worst).

Space Complexity:
The space complexity of Selection Sort is O(1) since it sorts the array in place without using any additional memory.

*/













// ++++++++++++++++++ Counting Sort +++++++++++++++++++++

// #include <iostream>
// #include <vector>
// using namespace std;

// // Fuction to perform Counting Sort
// void countingSort(vector<int> & arr, int n){
//     // Find the maximum element in the array 
//     int max_val = arr[0];
//     for(int i = 1; i < n; i++){
//         if (arr[i] > max_val){
//             max_val = arr[i];
//         }
//     }

//     // Initialize a count array with zeros
//     vector<int> count(max_val + 1, 0);

//     // Store the count of each element in the count array
//     for (int i = 0; i < n; i++){
//         count[arr[i]]++;
//     }

//     // Store the sorted elements back into the original array
//     int index = 0;
//     for (int i = 0; i <= max_val; i++){
//         while(count[i] > 0){
//             arr[index++] = i;
//             count[i]--;
//         }
//     }
// }

// // Function to print an array
// void printArray(const vector<int>& arr){
//     for (int i = 0; i < arr.size(); i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     vector<int> arr  = {4, 2, 2, 8, 3, 3, 1};
//     int n = arr.size();

//     cout << "Original Array: ";
//     printArray(arr);

//     countingSort(arr, n);

//     cout << "Sorted Array: ";
//     printArray(arr);

//     return 0;
// }




/*

Explanation:
Counting Sort Function:

The countingSort function takes a vector<int> and its size as input.

It first finds the maximum element in the array to determine the range of the count array.

It initializes a count array with zeros and stores the count of each element in the array.

It places the sorted elements back into the original array by iterating through the count array.

Print Array Function:

The printArray function prints the elements of the array using a loop.

Main Function:

The main function initializes a vector<int> with the array values.

It prints the original array.

It calls the countingSort function to sort the array.

It prints the sorted array.

*/















// +++++++++++++++ Radix Sort ++++++++++++++++++++++

// #include <iostream>
// #include <vector>
// using namespace std;

// // A utility function to get the maximum value in arr[]
// int getMax(const vector<int>& arr){
//     int max_val = arr[0];
//     for (int val : arr){
//         if (val > max_val){
//             max_val = val;
//         }
//     }
//     return max_val;
// }

// // A function to perform counting sort on arr[] according to the digit represented by exp
// void countingSort(vector<int>& arr, int exp){
//     int n = arr.size();
//     vector<int> output(n);   // Output array
//     vector<int> count(10, 0);  // Count array to store count of occurrencess of digits (0-9)

//     // Store count of occurrences of digits
//     for (int i = 0; i < n; i++){
//         count[(arr[i] / exp) % 10]++;
//     }

//     // Change count[i] so that it contains the actual position of this digit in the output array
//     for(int i = 1; i < 10; i++){
//         count[i] += count[i - 1];
//     }

//     // Build the output array
//     for(int i = n-1; i >= 0; i--){
//         output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//         count[(arr[i] / exp) % 10]--;
//     }

//     // Copy the outpu array to arr[], so that arr now contains sorted numbers according to the current digit
//     for(int i = 0; i < n; i++){
//         arr[i] = output[i];
//     }
// }

// // The main function to that sorts arr[] of size n using Radix Sort
// void radixSort(vector<int>& arr){
//     // Find the maximum number to know the number of digits
//     int max_val = getMax(arr);

//     // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
//     for (int exp = 1; max_val / exp > 0; exp *= 10){
//         countingSort(arr, exp);
//     }
// }

// // Function to print an array
// void printArray(const vector<int>& arr){
//     for(int val : arr){
//         cout << val << " ";
//     }
//     cout << endl;
// }

// int main(){
//     vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

//     cout << "Original array: ";
//     printArray(arr);

//     radixSort(arr);

//     cout << "Sorted array: ";
//     printArray(arr);

//     return 0;

// }


/*

Explanation:
Get Maximum Function:

The getMax function finds the maximum value in the array. This helps determine the number of digits in the largest number.

Counting Sort Function:

The countingSort function performs counting sort on the array based on the digit represented by exp (1's place, 10's place, 100's place, etc.).

It uses a count array to store the count of each digit and then builds the output array accordingly.

Radix Sort Function:

The radixSort function sorts the array by performing counting sort for every digit (starting from the least significant digit to the most significant digit).

Print Array Function:

The printArray function prints the elements of the array.

Main Function:

The main function initializes a vector with the array values.

It prints the original array.

It calls the radixSort function to sort the array.

It prints the sorted array.

Time Complexity:
The time complexity of Radix Sort is O(d * (n + k)), where d is the number of digits in the maximum number, n is the number of elements in the array, and k is the range of the input digits (0-9 for decimal digits).

Space Complexity:
The space complexity of Radix Sort is O(n + k) due to the count and output arrays.


*/















// +++++++++++++++++ Other Method for Radix Sort +++++++++++++++

#include<iostream>
#include<vector>
using namespace std;

// Function to find the maximum value in the array
int findMax(const vector<int>& arr){
    int max = arr[0];
    for(int val : arr){
        if (val > max){
            max = val;
        }
    }
    return max;
}

// Radix Sort function 
void radixSort(vector<int>& arr){
    int n = arr.size();
    int maxVal = findMax(arr);
    int exp = 1;

    while(maxVal / exp > 0) {
        vector<vector<int>> radixArray(10);
        for (int val : arr){
            int radixIndex = (val / exp) % 10;
            radixArray[radixIndex].push_back(val);
        }

        int pos = 0;
        for (int i = 0; i < 10; i++){
            for(int j = 0; j < radixArray[i].size(); j++){
                arr[pos] = radixArray[i][j];
                pos++;
            }
        }
        exp *= 10;
    }
}

// Funcito to print an array
void printArray(const vector<int>& arr){
    for (int val : arr){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    vector<int> myArray = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    printArray(myArray);

    radixSort(myArray);

    cout << "Sorted array: ";
    printArray(myArray);

    return 0;
}





/*

Explanation:
findMax Function:

The findMax function takes a reference to a vector and finds the maximum value in the array.

radixSort Function:

The radixSort function sorts the array using the Radix Sort algorithm.

It creates a 2D vector radixArray to hold the values for each digit.

It distributes the elements into the radixArray based on the current digit (exp).

It then collects the values back into the original array.

The process is repeated for each digit.

printArray Function:

The printArray function prints the elements of the array.

Main Function:

The main function initializes a vector with the array values.

It prints the original array.

It calls the radixSort function to sort the array.

It prints the sorted array.


Time Complexity:
Finding the maximum value:

The function findMax iterates through the array once to find the maximum value.

Time complexity: O(n)

Sorting each digit:

Radix Sort processes each digit of the maximum number.

If d is the number of digits in the maximum number, the number of passes needed is d.

For each pass, counting sort (or distribution count) is used, which takes O(n) time.

Therefore, the total time complexity of Radix Sort is O(d * n), where d is the number of digits in the maximum number and n is the number of elements in the array. In the case of fixed-length integers (e.g., 32-bit or 64-bit integers), d is a constant, making the time complexity effectively O(n).

Space Complexity:
Count array:

The count array's size is based on the range of digits (0-9), which is a constant size.

Space complexity: O(k) where k is the range of digits. Since k is a constant (10 in this case), it can be considered O(1).

Output array:

An additional array is used to store the sorted output of each pass.

Space complexity: O(n)

Overall, the space complexity of Radix Sort is O(n) due to the additional output array.

Summary:
Time Complexity: O(d * n)

Space Complexity: O(n)

Radix Sort is efficient for sorting integers or strings where the number of digits (or characters) is relatively small compared to the number of elements. It is especially useful for large datasets with a fixed-length key.
*/