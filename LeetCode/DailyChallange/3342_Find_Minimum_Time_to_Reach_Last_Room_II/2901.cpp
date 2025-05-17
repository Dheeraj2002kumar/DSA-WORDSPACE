
# Code
```cpp
class Solution {
    int hammingDistance(const string &a, const string &b) {
        int hamming_distance = 0;
        for (int i = 0, n = a.size(); i < n; ++i)
            if (a[i] != b[i])
                ++hamming_distance;
        return hamming_distance;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> lis(n, 1), parent(n, -1);

        int lis_len = 1, lis_end = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j]
                    && words[i].size() == words[j].size()
                    && hammingDistance(words[i], words[j]) == 1
                    && lis[i] + 1 > lis[j])
                {
                    lis[j] = lis[i] + 1;
                    parent[j] = i;
                    if (lis[j] > lis_len) {
                        lis_len = lis[j];
                        lis_end = j;
                    }
                }
            }
        }

        // reconstruct subsequence
        vector<string> ans;
        for (int cur = lis_end; cur != -1; cur = parent[cur])
            ans.push_back(words[cur]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/*
2901. Longest Unequal Adjacent Groups Subsequence II

# Intuition
The problem requires finding the longest subsequence of words where:
- Consecutive words belong to different groups,
- They are of the same length, and
- They differ by exactly one character (i.e., Hamming distance is 1).

The first thought is to treat each word as a node in a graph, and draw an edge between two nodes if the above three conditions are met. Then, the task becomes finding the longest path in this implicit graph — specifically, a Longest Increasing Subsequence (LIS)-like approach but with custom conditions.

# Approach
We iterate over all pairs of words and check whether they satisfy the given constraints:
1. They must come from different groups.
2. They must be the same length.
3. They must differ by exactly one character (using a helper function to calculate Hamming distance).

We use a dynamic programming array `lis` where `lis[i]` stores the length of the longest valid subsequence ending at index `i`. We also maintain a `parent` array to reconstruct the actual sequence later.

During the nested iteration, if word `j` can follow word `i` in the valid subsequence, we update `lis[j]` and `parent[j]` accordingly.

Finally, we reconstruct the longest subsequence using the `parent` array, starting from the end of the longest valid path.

# Complexity
- Time complexity:  
  $$O(n^2 \cdot m)$$  
  where \( n \) is the number of words, and \( m \) is the length of each word. This is because for each word pair, we compute the Hamming distance, which takes \( O(m) \) time.

- Space complexity:  
  $$O(n)$$  
  for the `lis`, `parent`, and final answer arrays.

# Code
```cpp
class Solution {
    int hammingDistance(const string &a, const string &b) {
        int hamming_distance = 0;
        for (int i = 0, n = a.size(); i < n; ++i)
            if (a[i] != b[i])
                ++hamming_distance;
        return hamming_distance;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> lis(n, 1), parent(n, -1);

        int lis_len = 1, lis_end = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (groups[i] != groups[j]
                    && words[i].size() == words[j].size()
                    && hammingDistance(words[i], words[j]) == 1
                    && lis[i] + 1 > lis[j])
                {
                    lis[j] = lis[i] + 1;
                    parent[j] = i;
                    if (lis[j] > lis_len) {
                        lis_len = lis[j];
                        lis_end = j;
                    }
                }
            }
        }

        // reconstruct subsequence
        vector<string> ans;
        for (int cur = lis_end; cur != -1; cur = parent[cur])
            ans.push_back(words[cur]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

*/
