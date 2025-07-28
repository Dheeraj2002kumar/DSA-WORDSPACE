// #include <iostream>
// using namespace std;

// void selectionSortAscendingOrder(int arr[], int n){
//     for (int i = 0; i < n - 1; i++){
//         int minIndex = i;

//         // find the index of the smallest element
//         for (int j = i+1; j < n; j++){
//             if (arr[j] < arr[minIndex]){
//                 minIndex = j;
//             }
//         }

//         // Swap the found minimum with the current element
//         if (minIndex != i){
//             swap(arr[i], arr[minIndex]);
//         }
//     }
// }

// void printArray(int arr[], int n){
//     for (int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout<<endl;
// }

// int main(){
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     selectionSortAscendingOrder(arr, n);
//     cout << "Sorted array in ascending order: ";
//     printArray(arr, n);

//     return 0;
// }

// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA/1_Sorting/1_Selection_Sort (main) $ g++ Selection_sort.cpp -o  Selection_sort
// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA/1_Sorting/1_Selection_Sort (main) $ ./Selection_sort 
// Sorted array in ascending order: 11 12 22 25 64 




// ------------------- User input ------------------

#include<iostream>
using namespace std;

int main(){
    int arr[1000];
    int n; 
    
    cout << "Enter the size of array: ";
    cin >> n;  // size of array

    cout << "Enter the element in array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; i++){
        int index = i;
        
        for(int j = i + 1; j < n; j++){
            if (arr[j] < arr[index]){
                index = j;
            }

        }
        swap(arr[i], arr[index]);

    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}

// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA/1_Sorting/1_Selection_Sort (main) $ g++ Selection_sort.cpp -o Selection_sort
// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA/1_Sorting/1_Selection_Sort (main) $ ./Selection_sort 
// Enter the size of array: 4
// Enter the element in array: 3 5 22 -2 6
// -2 3 5 22 
// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA/1_Sorting/1_Selection_Sort (main) $ 