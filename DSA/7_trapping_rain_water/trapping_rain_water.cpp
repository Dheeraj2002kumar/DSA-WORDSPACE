/*

42. Trapping Rain Water
Solved
Hard
Topics
premium lock icon
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int water = 0;
        int leftmax = 0, rightmax = 0;
        int maxheight = height[0], index = 0;

        // Find index of the maximum height bar
        for (int i = 1; i < n; i++) {
            if (height[i] > maxheight) {
                maxheight = height[i];
                index = i;
            }
        }

        // Traverse from left to the max height index
        for (int i = 0; i < index; i++) {
            if (height[i] < leftmax) {
                water += leftmax - height[i];
            } else {
                leftmax = height[i];
            }
        }

        // Traverse from right to the max height index
        for (int i = n - 1; i > index; i--) {
            if (height[i] < rightmax) {
                water += rightmax - height[i];
            } else {
                rightmax = height[i];
            }
        }

        return water;
    }
};

int main() {
    Solution sol;

    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water (Example 1): " << sol.trap(height1) << endl; // Output: 6

    vector<int> height2 = {4,2,0,3,2,5};
    cout << "Trapped water (Example 2): " << sol.trap(height2) << endl; // Output: 9

    return 0;
}
