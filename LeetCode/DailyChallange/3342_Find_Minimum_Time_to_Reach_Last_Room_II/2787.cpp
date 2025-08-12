/*

2787. Ways to Express an Integer as Sum of Powers
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

 

Example 1:

Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
Example 2:

Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.
 

Constraints:

1 <= n <= 300
1 <= x <= 5

*/

class Solution {
    #define MOD 1000000007

    int binaryExponentiation(int a,int b){
        int res = 1;
        while(b){
            if(b&1)
                res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }
public:
    int numberOfWays(int n, int x) {
        // Step-1: Calculate powers array
        vector<int> powers;
        for(int i=1;i<=n;++i){
            int power = binaryExponentiation(i,x);
            if(power>n)//Can't include any more powers
                break;
            
            powers.push_back(power);
        }
        // Step-2: Apply Tabulation
        vector<int> dp(n+1);
        dp[0] = 1;
        int p = powers.size();
        for(int pos=1;pos<=p;++pos){
            for(int target=n;target>=powers[pos-1];--target){
                dp[target] = (dp[target] + dp[target-powers[pos-1]]) % MOD;
            }
        }
        return dp[n];
    }
};