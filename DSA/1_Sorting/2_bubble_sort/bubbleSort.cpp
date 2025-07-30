// #include<iostream>
// using namespace std;

// void bubbleSort(int arr[], int n){
//     bool swapped;
//     for(int i = 0; i < n - 1; i++){
//         swapped = false;

//         for (int j = 0; j < n - 1; j++){
//             if (arr[j] > arr[j + 1]){
//                 // swap
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;

//                 swapped = true;
//             }
//         }

//         // If no two elements were swapped, array is sorted
//         if (!swapped){
//             break;
//         }
//     }
// }

// void printArray(int arr[], int size){
//     for (int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Before sorting: ";
//     printArray(arr, n);

//     bubbleSort(arr, n);

//     cout << "Sorted array in ascending order: ";
//     printArray(arr, n);

//     return 0;
// }



// ------------- user input ---------------

#include<iostream>
using namespace std;

int main(){
    int arr[1000];
    int n;
    
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the element in array: ";

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--){
        bool swapped = 0;
        for (int j = 0; j <= i; j++){

            if (arr[j] > arr[j + 1]){
                swapped = 1;
                swap(arr[j], arr[j+1]);
            }
        }

        if (swapped == 0){
            break;
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}