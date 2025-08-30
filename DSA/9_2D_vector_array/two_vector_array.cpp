#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void wave(int arr[][4], int row, int col){
    for (int j = 0; j < col; j++){
        // if even
        if (j%2 == 0){
            for (int i = 0; i < row; i++){
                cout << arr[i][j] << " ";
            }
        }
        // if odd
        else{
            for (int i = row-1; i >= 0; i--){
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    // create 2d vector
    // vector<vector<int> > matrix(3, vector<int>(4, 1));

    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 4; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // // check vector matrix row and column size
    // cout << "Rows = " << matrix.size();
    // cout << endl;
    // cout << "Cols = " << matrix[0].size();



    // -------------------------------------------

    // take user input for 2D vector array

    // int n, m;
    // cout << "Enter rows and col: ";
    // cin >> n >> m;
    // vector<vector<int> > matrix(n, vector<int>(m, 1));

    // cout << "Enter the value for matrix: ";
    
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cin >> matrix[i][j];
    //     }
    // }

    // for (int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    // ----------------------------------------------

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int ans[3][4]; 

    // wave print
    wave(arr1, 3, 4);
    return 0;
}