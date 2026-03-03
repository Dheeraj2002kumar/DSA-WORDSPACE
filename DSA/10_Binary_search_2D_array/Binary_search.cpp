#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size(), M = matrix[0].size();
        int row_index, col_index, start = 0, end = N*M-1, mid;

        while(start <= end){
            mid = start+(end-start)/2;
            row_index = mid/M;
            col_index = mid%M;

            if(matrix[row_index][col_index] == target) return true;
            else if (matrix[row_index][col_index] < target) start = mid+1;
            else end = mid-1;
        }

        return false;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {12, 15, 18, 19},
        {20, 22, 25, 27},
        {30, 32, 35, 38}
    };

    int target = 11;

    if (solution.searchMatrix(matrix, target)){
        cout << "true" << endl;
    } else{
        cout << "false" << endl;
    }

    return 0;
}