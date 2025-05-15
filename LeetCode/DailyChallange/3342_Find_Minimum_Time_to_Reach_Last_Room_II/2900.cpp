class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> result;
        for (int i = 0; i < n; i++){
            if (i == 0 || groups[i] != groups[i-1]){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};




/*
#2900. Longest Unequal Adjacent Groups Subsequence 

# Intuition

When examining the problem, it becomes clear that we are looking to extract a subsequence of words where consecutive elements come from different groups. The key insight is to iterate through the list and only select a word if its group differs from the previous one. This naturally forms the longest possible subsequence under the given constraint.

# Approach

We iterate through the `words` list alongside the `groups` list. Starting from the first word, we compare each word's group with the previous one. If it's different, we add the word to our result. This ensures that no two consecutive words in the result are from the same group.

This greedy approach guarantees the longest subsequence since at every point, we include a word only if it maintains the rule (no consecutive same-group elements). It requires only one pass through the list.

# Complexity

* **Time complexity:**
  $O(n)$
  We iterate through the `words` and `groups` list once, where $n$ is the number of elements in the list.

* **Space complexity:**
  $O(n)$
  In the worst case, the result may include all elements from `words`, requiring additional space proportional to the size of the input.

# Code
```cpp []
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> result;
        for (int i = 0; i < n; i++){
            if (i == 0 || groups[i] != groups[i-1]){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
```
*/
