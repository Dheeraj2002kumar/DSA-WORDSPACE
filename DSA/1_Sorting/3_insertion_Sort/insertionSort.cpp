// #include<iostream>
// using namespace std;

// int main(){
//     int arr[1000];
//     int n;

//     cout << "Enter the size of array: ";
//     cin >> n;

//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     for (int i = 1; i < n; i++){

//         for(int j = i; j > 0; j--){

//             if (arr[j] < arr[j-1]){
//                 swap(arr[j], arr[j-1]);
//             }
//             else{
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }




// ---------------- --------------

#include <iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr){
    int n = arr.size();

    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(const vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << "\n";
}

int main(){
    vector<int> arr = {8, 5, 1, 4, 3};

    cout << "Original array:\n";
    printArray(arr);

    insertionSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}