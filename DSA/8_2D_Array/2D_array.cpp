#include<iostream>
using namespace std;

void printCal(int arr[][4], int row, int col){
    for(int j = 0; j < col; j++){
        for (int i = 0; i < row; i++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

void printRowMax(int arr[][4], int row, int col){
    int index = -1, maxSum = INT_MIN;

    for (int i = 0; i < row; i++){
        int sum = 0; 
        for(int j = 0; j < col; j++){
            sum += arr[i][j];

            if (sum > maxSum){
                maxSum = sum;
                index = i;
            }
        }
    }
    cout << "Maximum value of in the column: "<< maxSum << endl;
    cout << "Index of the row: " << index << endl;
}

int main(){
    // create 2D array
    int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int arr1[3][4] = {0, 2, 3, 4, 5, 33, 5, 33, 6, 7, 8, 33};
    int sumOfTwoArray[3][4];

    // ----------------------------------------

    // // print all the value in array row wise
    // for (int row = 0; row < 3; row++){
    //     for (int col = 0; col < 4; col++){
    //         cout << arr[row][col] << " ";
    //     }
    // }

    // cout << endl;

    // // print all the value in array column wise using function call
    // printCal(arr, 3, 4);

    // -----------------------------------------------------

    // find an element in our array
    
    // int x = 7;

    // for (int row = 0; row < 3; row++){
    //     for (int col = 0; col < 4; col++){
    //         if (arr[row][col] == x){
    //             cout << "Yes ";
    //             return 0;
    //         }
    //     }
    // }
    // cout << "No";

    // -----------------------------------------------

    // add two matrix

    // for (int row = 0; row < 3; row++){
    //     for (int col = 0; col < 4; col++){
    //         sumOfTwoArray[row][col] = arr[row][col] + arr1[row][col];
    //     }
    // }

    // // print sumOfTwoArray matrix
    // cout << "sumOfTwoArray matrix is:  " << endl;

    // for (int row = 0; row < 3; row++){
    //     for (int col = 0; col < 4; col++){
    //         cout << sumOfTwoArray[row][col] << " ";
    //     }
    // }
    // cout << endl;


    // -------------------------------------------

    // print maximum column index and value
    printRowMax(arr, 3, 4);

    return 0;
}