class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool zero_row = false;
        bool zero_col = false;
        for (int i = 0; i < m; ++i){
            if (matrix[i][0] == 0){
                zero_row = true;
                break;
            }
        }

        for (int i = 0; i < n; ++i){
            if (matrix[0][i] == 0){
                zero_col = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i){
            if (matrix[i][0] == 0){
                for (int j = 1; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; ++i){
            if (matrix[0][i] == 0){
                for (int j = 1; j < m; ++j){
                    matrix[j][i] = 0;
                }
            }
        }

        if (zero_row){
            for (int i = 0; i < m; ++i){
                matrix[i][0] = 0;
            }
        }

        if (zero_col){
            for (int j = 0; j < n; ++j){
                matrix[0][j] = 0;
            }
        }

        
    }
};


/*

# Intuition

The key idea is to use the first row and the first column of the matrix to keep track of which rows and columns need to be zeroed. This avoids the need for additional space and allows us to update the matrix in-place efficiently.

When we encounter a zero in the matrix, it means the entire row and column containing that zero should also be set to zero. Instead of using extra space like a separate boolean matrix or set, we cleverly use the first row and column as markers to note which rows and columns should eventually be zeroed.

# Approach

1. First, determine if the first row or the first column needs to be zeroed by checking for any zeros in them.
2. Iterate through the rest of the matrix. If a cell at position `(i, j)` is 0, mark `matrix[i][0]` and `matrix[0][j]` as 0.
3. Using the markers from step 2, update the matrix:

   * Zero out rows based on the markers in the first column.
   * Zero out columns based on the markers in the first row.
4. Finally, handle the first row and column separately based on the flags from step 1.

This approach maintains constant space complexity and avoids modifying the matrix while scanning for initial zeros.

# Complexity

* **Time complexity:**
  $O(m \times n)$
  where *m* is the number of rows and *n* is the number of columns. We traverse the matrix multiple times, but each operation is still linear in terms of the matrix size.

* **Space complexity:**
  $O(1)$
  We do not use any additional space apart from a few boolean variables. The matrix is modified in-place.

# Code
```cpp []
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool zero_row = false;
        bool zero_col = false;
        for (int i = 0; i < m; ++i){
            if (matrix[i][0] == 0){
                zero_row = true;
                break;
            }
        }

        for (int i = 0; i < n; ++i){
            if (matrix[0][i] == 0){
                zero_col = true;
                break;
            }
        }

        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i){
            if (matrix[i][0] == 0){
                for (int j = 1; j < n; ++j){
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; ++i){
            if (matrix[0][i] == 0){
                for (int j = 1; j < m; ++j){
                    matrix[j][i] = 0;
                }
            }
        }

        if (zero_row){
            for (int i = 0; i < m; ++i){
                matrix[i][0] = 0;
            }
        }

        if (zero_col){
            for (int j = 0; j < n; ++j){
                matrix[0][j] = 0;
            }
        }

        
    }
};
```

*/
