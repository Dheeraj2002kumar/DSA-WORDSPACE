/*

869. Reordered Power of 2

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

 

Example 1:

Input: n = 1
Output: true
Example 2:

Input: n = 10
Output: false
 

Constraints:

1 <= n <= 109

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