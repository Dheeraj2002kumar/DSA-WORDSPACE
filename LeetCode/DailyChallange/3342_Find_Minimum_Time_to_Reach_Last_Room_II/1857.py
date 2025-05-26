class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for src, dst in edges:
            adj[src].append(dst)

        def dfs(node):
            if node in path:
                return float("inf")
            
            if node in visit:
                return 0
            visit.add(node)
            path.add(node)

            colorIndex = ord(colors[node]) - ord('a')
            count[node][colorIndex] = 1

            for nei in adj[node]:
                if dfs(nei) == float("inf"):
                    return float("inf")
                
                for c in range(26):
                    count[node][c] = max(
                        count[node][c],
                        (1 if c == colorIndex else 0) + count[nei][c]
                    )
            
            path.remove(node)
            return max(count[node])

        n, res = len(colors), 0
        visit, path = set(), set()
        count = [[0] * 26 for i in range(n)]  # Map count [node][color] --> max freq color

        for i in range(n):
            res = max(dfs(i), res)
        return -1 if res == float("inf") else res


'''
# Intuition

The problem asks for the maximum number of nodes with the same color in any valid path of a directed graph. My first thought was that this is a graph traversal problem, but with a twist: instead of just visiting nodes, we need to keep track of how frequently each color appears along all paths.

A key insight is that if there's a cycle, we should immediately return `-1` since it's impossible to determine a "path value" (as the path could go on forever). This hinted at using DFS with cycle detection and memoization.

---

# Approach

1. **Build the Graph**: Use an adjacency list (`adj`) to represent the directed graph from the list of edges.

2. **DFS with Cycle Detection**:

   * Perform a DFS from each node.
   * Use a `path` set to track the current DFS path. If we revisit a node on the same path, it's a cycle.
   * Use a `visit` set to avoid re-processing nodes we've already completed.

3. **Track Color Frequencies**:

   * Maintain a 2D list `count[node][color]` to record the maximum number of times a specific color appears on any path leading to that node.
   * For each neighbor in DFS, update the current node's color count using the neighbor's values.

4. **Return the Result**:

   * After visiting all nodes, return the highest value found in any `count[node]`.
   * If any cycle is detected during DFS, return `-1`.

---

# Complexity

* **Time complexity:**
  $O(n + e + 26n) = O(n + e)$

  * Where $n$ is the number of nodes, $e$ is the number of edges.
  * For each node, we process all 26 colors once during the DFS.

* **Space complexity:**
  $O(n \cdot 26 + n + e) = O(n + e)$

  * `count` takes $O(26n)$, sets `visit` and `path` take $O(n)$, and the adjacency list takes $O(e)$.


# Code
```python3 []
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        adj = defaultdict(list)
        for src, dst in edges:
            adj[src].append(dst)

        def dfs(node):
            if node in path:
                return float("inf")
            
            if node in visit:
                return 0
            visit.add(node)
            path.add(node)

            colorIndex = ord(colors[node]) - ord('a')
            count[node][colorIndex] = 1

            for nei in adj[node]:
                if dfs(nei) == float("inf"):
                    return float("inf")
                
                for c in range(26):
                    count[node][c] = max(
                        count[node][c],
                        (1 if c == colorIndex else 0) + count[nei][c]
                    )
            
            path.remove(node)
            return max(count[node])

        n, res = len(colors), 0
        visit, path = set(), set()
        count = [[0] * 26 for i in range(n)]  # Map count [node][color] --> max freq color

        for i in range(n):
            res = max(dfs(i), res)
        return -1 if res == float("inf") else res
```

'''
