/*
-------- String Rotated by 2 Places -----------------

Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.

Note: Both rotations should be performed in same direction chosen initially.

Examples:

Input: s1 = "amazon", s2 = "azonam"
Output: true
Explanation: "amazon" can be rotated anti-clockwise by two places, which will make it as "azonam".
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void rotateAnticlockwise(string &s) {
        char c = s[0];
        int index = 1;
        while (index < s.size()) {
            s[index - 1] = s[index];
            index++;
        }
        s[s.size() - 1] = c;
    }

    void rotateClockwise(string &s) {
        char c = s[s.size() - 1];
        int index = s.size() - 2;
        while (index >= 0) {
            s[index + 1] = s[index];
            index--;
        }
        s[0] = c;
    }

    // Check if s2 can be obtained by rotating s1 exactly 2 positions
    bool isRotated(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;

        string clockwise = s1;
        rotateClockwise(clockwise);
        rotateClockwise(clockwise);
        if (clockwise == s2) return true;

        string anticlockwise = s1;
        rotateAnticlockwise(anticlockwise);
        rotateAnticlockwise(anticlockwise);
        if (anticlockwise == s2) return true;

        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (sol.isRotated(s1, s2)) {
        cout << "Yes, the second string is a rotation of the first by 2 positions." << endl;
    } else {
        cout << "No, the second string is NOT a rotation of the first by 2 positions." << endl;
    }

    return 0;
}