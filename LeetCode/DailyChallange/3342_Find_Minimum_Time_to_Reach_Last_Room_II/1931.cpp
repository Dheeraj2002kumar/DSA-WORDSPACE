class Solution {
public:

    vector<string> columnStates;
    int M = 1e9+7;
    vector<vector<int>> t;

    void generateColumnStates(string curr, char prevChar, int l, int m){
        if (l == m){
            columnStates.push_back(curr);
            return;
        }

        for (char ch: {'R', 'G', 'B'}){
            if (ch == prevChar){
                continue;
            }
            generateColumnStates(curr + ch, ch, l+1, m);
        }
    }

    int solve(int remainCols, int prevIdx, int m){
        if (remainCols == 0){
            return 1;
        }

        if (t[remainCols][prevIdx] != -1){
            return t[remainCols][prevIdx];
        }

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++){
            if (i == prevIdx) continue;

            string currState = columnStates[i];
            bool valid = true;
            
            for (int j = 0; j < m; j++){
                if (prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }

            if (valid){
                ways = (ways + solve(remainCols-1, i, m)) % M;
            }
        }
        return t[remainCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateColumnStates("", '#', 0, m);

        int totalStates = columnStates.size();

        t = vector<vector<int>>(n+1, vector<int>(totalStates + 1, -1) );

        int result = 0;
        for (int i = 0; i < columnStates.size(); i++){
            result = (result + solve(n-1, i, m)) % M;
        }
        return result;
    }
};



/*
# 1931. Painting a Grid With Three Different Colors

# Intuition

To solve the problem of coloring a `m x n` grid using 3 colors such that:

* No two adjacent cells in the same column have the same color.
* No two adjacent cells in the same row have the same color.

We can think of coloring the grid column by column. Since only adjacent cells need to differ, we can generate all valid color combinations for a single column, then try to build the grid by connecting compatible columns.

# Approach

1. **Generate Valid Column States**:
   We use DFS to generate all valid column configurations (of height `m`) where no two adjacent cells are the same color.

2. **Dynamic Programming**:

   * We define a DP table `t[remainCols][prevIdx]` where `remainCols` is the number of columns left to fill and `prevIdx` is the index of the previously used column state.
   * For each valid current column state, we check whether it's compatible with the previous column state (i.e., for every row, the color in the current column differs from the previous column).
   * If compatible, recursively compute the number of valid ways for the remaining columns.

3. **Combine Results**:
   Start with every possible column configuration as the first column and sum all valid combinations to get the final answer.

# Complexity

* **Time complexity**:
  $O(n \cdot s^2 \cdot m)$
  where `n` is the number of columns, `s` is the number of valid column states (depends on `m`), and `m` is the number of rows.
  Each column can be any of the valid `s` states, and we check compatibility between each pair.

* **Space complexity**:
  $O(n \cdot s)$
  For the memoization table `t`, and storing all valid column states.

# Code
```cpp []
class Solution {
public:

    vector<string> columnStates;
    int M = 1e9+7;
    vector<vector<int>> t;

    void generateColumnStates(string curr, char prevChar, int l, int m){
        if (l == m){
            columnStates.push_back(curr);
            return;
        }

        for (char ch: {'R', 'G', 'B'}){
            if (ch == prevChar){
                continue;
            }
            generateColumnStates(curr + ch, ch, l+1, m);
        }
    }

    int solve(int remainCols, int prevIdx, int m){
        if (remainCols == 0){
            return 1;
        }

        if (t[remainCols][prevIdx] != -1){
            return t[remainCols][prevIdx];
        }

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++){
            if (i == prevIdx) continue;

            string currState = columnStates[i];
            bool valid = true;
            
            for (int j = 0; j < m; j++){
                if (prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }

            if (valid){
                ways = (ways + solve(remainCols-1, i, m)) % M;
            }
        }
        return t[remainCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateColumnStates("", '#', 0, m);

        int totalStates = columnStates.size();

        t = vector<vector<int>>(n+1, vector<int>(totalStates + 1, -1) );

        int result = 0;
        for (int i = 0; i < columnStates.size(); i++){
            result = (result + solve(n-1, i, m)) % M;
        }
        return result;
    }
};
```
*/
