/*

Problem Description
You are given two strings, a main string S, and a pattern P.You have to find the starting indices of the anagrams of P in S.


Anagrams are permutations of a string.For P = "abc”, its anagrams are abc,acb,bca,bac,cba,cab.


Note that indexing starts at 0.

Input format
There is one line of input, containing two space - separated strings S and P.

Output format
First - line should contain the number of such starting indices.

Next line should contain the indices in increasing order separated by a space.

Sample Input 1
aaba ab

Sample Output 1
2

1 2

Explanation 1
The anagrams of pattern "ab" are “ab” and “ba”. These are present at indices 1 and 2 of the input string “aaba”.

Sample Input 2
bacdgabcda abcd

Sample Output 2
3

0 5 6

Explanation 2
The anagrams of "abcd" can be seen as “bacd” at index 0, “abcd” at index 5 and “bcda” at index 6.

Constraints
1 <= length(S), length(P) <= 10 ^ 6

Pattern Introduction
image


For the brute force approach ignore the time complexity mentioned at 6: 40 in this video.The actual time complexity for the brute force approach would be O(M ^ 2 * M! + N * M!).O(M ^ 2 * M!) for finding all anagrams of the pattern as there will be M! Anagrams and in worst case the for loop inside findAllAnagramsOfPattern function would take O(M ^ 2) time and O(N * M!) for the "for loop" present inside findAnagramIndices function (the contains() method would linearly search all M! anagrams).
*/


/**
 * Function to find all the starting indices of the anagrams of P in S
 * @param {string} s - Main string
 * @param {string} p - Pattern string (for which anagrams need to be found)
 * @return {number[]} - Array of indices where anagrams start
 */
function findAllAnagramsInAString(s, p) {
    let n = s.length;
    let m = p.length;
    let result = [];

    // If the pattern is longer than the string, no anagrams can exist
    if (n < m) return result;

    // Frequency arrays for pattern and current window in string
    let pCount = Array(26).fill(0);
    let windowCount = Array(26).fill(0);

    // Fill the frequency array for pattern `p`
    for (let char of p) {
        pCount[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // Sliding window over string `s`
    for (let i = 0; i < n; i++) {
        // Add current character to window count
        windowCount[s[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;

        // If we have scanned enough characters, check the window
        if (i >= m) {
            // Remove the character that is sliding out of the window
            windowCount[s[i - m].charCodeAt(0) - 'a'.charCodeAt(0)]--;
        }

        // If window size equals the pattern size, compare counts
        if (i >= m - 1 && arraysAreEqual(pCount, windowCount)) {
            result.push(i - m + 1);
        }
    }

    return result;
}

// Main function to read input and process the query
function main() {
    let [s, p] = readLine().split(" "); // Read both strings S and P
    let result = findAllAnagramsInAString(s, p); // Find all anagrams' starting indices

    console.log(result.length); // Output the number of starting indices
    if (result.length > 0) {
        console.log(result.join(" ")); // Output the starting indices space-separated
    }
}
