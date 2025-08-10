/*

231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
    string getSortedStr(int n){
        string s = to_string(n);  // 10 digits // 0(d)
        sort(begin(s), end(s));  // O(dlogd)
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        // check all 2 powers and see if it matches with s
        // 2^29
        for (int p = 0; p <= 29; p++){
            if (s == getSortedStr(1 << p)){
                return  true;
            }
        }

        return false;
    }
};