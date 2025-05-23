class Solution {
    #define ll long long
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        ll count = 0; 
        ll discardedNode = INT_MAX;

        for (ll num: nums){
            ans += max(num, num^k);
            count += (num^k) > num;
            discardedNode = min(discardedNode, abs(num - (num^k)));
        }
        return count % 2 == 0 ? ans: (ans - discardedNode);
    }
};


/*
# Intuition

The problem involves maximizing the sum of a modified array. Each element can be optionally XOR-ed with a given value `k`, and the goal is to choose whether to XOR each element in a way that the final sum is maximized. A naive solution would be to try all combinations, but we notice that each XOR operation can be done independently. We can therefore consider whether each individual transformation increases the sum.

# Approach

1. Iterate through the array `nums`.
2. For each element, calculate the value after XOR with `k` (i.e., `num ^ k`).
3. If the XOR-ed value is greater than the original, choose it; otherwise, keep the original.
4. Maintain a count of how many values we switched (i.e., how many times `num ^ k > num`).
5. Also track the smallest absolute difference between the original and XOR-ed values. This will be useful if the count of switches is odd.
6. If the count of XOR switches is even, we're good — the sum is optimal.
7. If it's odd, we need to make it even by removing the smallest gain — subtract the smallest difference tracked earlier.

This clever trick ensures that we always end up with the optimal sum while also adhering to the rule that the number of XOR-ed nodes needs to be even (a typical constraint in some graph/DP problems, though not explicitly shown here).

# Complexity

* **Time complexity:**
  $O(n)$
  We only pass through the list once to compute all necessary values.

* **Space complexity:**
  $O(1)$
  We use a constant amount of extra space regardless of the input size.

# Code
```cpp []
class Solution {
    #define ll long long
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll ans = 0;
        ll count = 0; 
        ll discardedNode = INT_MAX;

        for (ll num: nums){
            ans += max(num, num^k);
            count += (num^k) > num;
            discardedNode = min(discardedNode, abs(num - (num^k)));
        }
        return count % 2 == 0 ? ans: (ans - discardedNode);
    }
};
```

*/
