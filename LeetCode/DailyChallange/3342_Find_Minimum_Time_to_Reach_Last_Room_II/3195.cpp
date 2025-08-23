/*
3195. Find the Minimum Area to Cover All Ones I
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

 

Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:



The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[1,0],[0,0]]

Output: 1

Explanation:



The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid.   
*/


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int low_x = INT_MAX, high_x = -1;
        int low_y = INT_MAX, high_y = -1;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 1){
                    low_x = min(low_x, i);
                    high_x = max(high_x, i);
                    low_y = min(low_y, j);
                    high_y = max(high_y, j);
                }
            }
        }
        return (high_x - low_x + 1) * (high_y - low_y + 1);
    }
};