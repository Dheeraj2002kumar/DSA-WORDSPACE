#include<iostream>
using namespace std;

int main(){
    // int x = 10;
    // int y = 20;

    // if (x > y){
    //     cout << "The x is largest " << x << endl;
    // } else {
    //     cout << "The y is largest " << y << endl;
    // }

    // int m, n, o;
    // cout << "Enter three number: " << endl;
    // cin >> m >> n >> o;

    // cout << endl;

    // if (m > n && m >> o){
    //     cout << "The largest number is " << m << endl;
    // } else if (n > o) {
    //     cout << "The largest number is " << n << endl;
    // } else {
    //     cout << "The largest number is " << o << endl;
    // }


    // cout << "Enter a negative number" << endl;
    // int z;
    // cin >> z;

    // int counter;
    // for (counter = 1; counter >= z; counter--){
    //     cout << counter << endl;
    // }

    // cout << "Enter a number" << endl;
    // int z;
    // cin >> z;

    // int counter;
    // int sum = 0;
    // for (counter = 1; counter <= z; counter++){
    //     if (counter%2 != 0){
    //         cout << counter << "\t";
    //         sum += sum+counter;
    //     }
    // }
    // cout << "\n" << sum << endl;


    // array --------------------
    // int number[10];
    // cout << "Enter 10 number: " << endl;

    // for (int i = 0; i < 10; i++){
    //     cin >> number[i];
    // }

    // cout << "The array elements are" << endl;
    // for (int i = 0; i < 10; i++){
    //     cout << "number[" << i << "] = " << number[i] << endl; 
    // }


    // ------------------ largest number -----------------
    // int number[10];
    // cout << "Enter 10 number: " << endl;

    // for (int i = 0; i < 10; i++){
    //     cin >> number[i];
    // }

    // int largest = number[0];
    // for (int i = 0; i < 10; i++){
    //     if (largest < number[i+1]){
    //         largest = number[i+1];
    //     }
    // }

    // cout << "The largest element is: " << largest << endl;



    // --------------------- 2D Array -------------------

    int matrix[3][3];
    int sumOfDiagonalEle = 0;
    int sumOfNoneDiagonalEle = 0;

    cout << "Enter matrix 9 numbers: " << endl;

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            cin >> matrix[row][col];
        }
    }

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }
    
    cout << "The Diagonal: " << endl;

    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){

            if (row == col){

                cout << matrix[row][col] << "\t";
                sumOfDiagonalEle += matrix[row][col];
            }
        }
        cout << endl;
    }
    
    cout << "None Diagonal element: " << endl;
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){

            if (row != col){

                cout << matrix[row][col] << "\t";
                sumOfNoneDiagonalEle += matrix[row][col];
            }
        }
        cout << endl;
    }


    cout << "Sum of Diagonoal Element: " << sumOfDiagonalEle << endl;
    cout << "Sum of None Diagonoal Element: " << sumOfNoneDiagonalEle << endl;


    return 0;
}

// ------Assignment ------
// row wise sum
// col wise sum
// transpose of sum
// addition of two matrix