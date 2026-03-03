#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (mat[row][col] == x) return true;
            else if (mat[row][col] < x) row++;
            else col--;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Sample matrix
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    // Test case 1
    int x = 29;
    bool result = sol.matSearch(mat, x);
    if (result) {
        cout << "Element " << x << " found in the matrix." << endl;
    } else {
        cout << "Element " << x << " not found in the matrix." << endl;
    }

    // Test case 2
    x = 100;
    result = sol.matSearch(mat, x);
    if (result) {
        cout << "Element " << x << " found in the matrix." << endl;
    } else {
        cout << "Element " << x << " not found in the matrix." << endl;
    }

    return 0;
}