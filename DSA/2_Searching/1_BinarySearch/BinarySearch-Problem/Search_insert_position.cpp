/*

35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, ans = nums.size(), mid;

        while(start <= end){
            mid = start + (end - start) / 2;
            if (nums[mid] == target){
                ans = mid;
                break;
            } else if (nums[mid] < target){
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int ans = s.searchInsert(nums, target);
    cout << ans << endl;



    return 0;
}

// ---------------- output --------------------

// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\DSA\2_Searching\1_BinarySearch\BinarySearch-Problem> g++ .\Search_insert_position.cpp -o Search_insert_position
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\DSA\2_Searching\1_BinarySearch\BinarySearch-Problem> ./Search_insert_position
// 2
// PS C:\Users\hp\Desktop\TCS IT\DSA-WORDSPACE\DSA\2_Searching\1_BinarySearch\BinarySearch-Problem>   
