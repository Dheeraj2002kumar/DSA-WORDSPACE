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