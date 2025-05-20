class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto& query: queries){
            int start = query[0];
            int end = query[1];
            diff[start]++;
            diff[end+1]--;
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=diff[i];
            if(sum<nums[i])
                return false;
        }
        return true;
    }
};

/*

# Intuition

The problem requires determining whether, after performing a set of increment operations on a given array, every element can be reduced to zero or below. Each query allows incrementing a subarray, and the task is to check whether the total number of such increments at each position is at least equal to the value at that index in the original array.

To solve this efficiently, a difference array can be used to apply range updates in constant time. By accumulating these differences, we can calculate the total increments at each position and compare with the original array.

---

# Approach

1. Initialize a difference array `diff` of size `n+1` with all zeros.
2. For each query `[start, end]`, increment `diff[start]` by 1 and decrement `diff[end + 1]` by 1.
3. Traverse the array using a prefix sum on the difference array to simulate the total increment at each index.
4. At each position `i`, compare the cumulative sum with `nums[i]`. If at any position the cumulative sum is less than `nums[i]`, return `false`.
5. If all positions meet the condition, return `true`.

This approach avoids applying each query directly to the array, improving performance from O(n \* q) to O(n + q).

---

# Complexity

* **Time complexity:**
  $O(n + q)$
  Where $n$ is the size of the array and $q$ is the number of queries.

  * Building the difference array takes O(q).
  * Applying prefix sum and checking conditions takes O(n).

* **Space complexity:**
  $O(n)$
  For the difference array of size $n + 1$.

---

# Code
```cpp []
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto& query: queries){
            int start = query[0];
            int end = query[1];
            diff[start]++;
            diff[end+1]--;
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=diff[i];
            if(sum<nums[i])
                return false;
        }
        return true;
    }
};
```
*/
