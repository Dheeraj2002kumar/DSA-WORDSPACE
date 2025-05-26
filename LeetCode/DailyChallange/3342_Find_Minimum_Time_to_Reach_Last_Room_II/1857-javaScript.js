/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    const n = colors.length;
    const adj = new Map();

    // build the adjacency list
    for (let i = 0; i < n; i++){
        adj.set(i, []);
    }

    for (const [src, dst] of edges){
        adj.get(src).push(dst);
    }

    const visit = new Set();
    const path = new Set();
    const count = Array.from({ length: n }, () => Array(26).fill(0));
    let res = 0;
    let hasCycle = false;

    const dfs = (node) => {
        if (path.has(node)) {
            hasCycle = true;
            return;
        }

        if (visit.has(node)){
            return;
        }

        visit.add(node);
        path.add(node);

        for (const nei of adj.get(node)){
            dfs(nei);
            if (hasCycle) return;
            for (let c = 0; c < 26; c++){
                count[node][c] = Math.max(count[node][c], count[nei][c]);
            }
        }

        const colorIndex = colors.charCodeAt(node) - 'a'.charCodeAt(0);
        count[node][colorIndex]++;
        res = Math.max(res, count[node][colorIndex]);

        path.delete(node);
    };

    for (let i = 0; i < n; i++){
        if (!visit.has(i)){
            dfs(i);
            if (hasCycle) return -1;
        }
    }
    return res;
};


/*

# Intuition

The problem involves finding the maximum number of occurrences of any single color in a valid path of a directed graph. The twist is that if there's a cycle, we must return `-1` because infinite paths are possible. Initially, this sounded like a classic graph traversal problem, but tracking color frequencies on paths and detecting cycles made it more complex. My first thought was to use **DFS with memoization and cycle detection**, while tracking color counts at each node.

---

# Approach

1. **Graph Construction**:
   Use an adjacency list to represent the graph from the `edges` array.

2. **DFS Traversal**:
   Perform DFS from every unvisited node. Use two sets:

   * `visit` to track visited nodes globally.
   * `path` to detect cycles in the current DFS path.

3. **Color Frequency Tracking**:
   Create a 2D array `count[node][color]` where each entry keeps the maximum frequency of that color on any path reaching that node.

4. **Cycle Detection**:
   If a node is revisited during the same DFS call (i.e., exists in `path`), a cycle is detected, and we set a flag to return `-1`.

5. **Result Accumulation**:
   After all DFS calls, we find the maximum value from the `count` table, which represents the highest number of a single color on any valid path.

---

# Complexity

* **Time complexity:**
  $O(n + e + 26n) = O(n + e)$

  * Building the graph: $O(e)$
  * DFS traversal: Each node is visited once → $O(n)$
  * Color frequency comparison per edge → $O(26n)$

* **Space complexity:**
  $O(n + e + 26n) = O(n + e)$

  * `adj`: $O(e)$
  * `visit`, `path`: $O(n)$
  * `count`: $O(26n)$

---

# Code
```javascript []
/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    const n = colors.length;
    const adj = new Map();

    // build the adjacency list
    for (let i = 0; i < n; i++){
        adj.set(i, []);
    }

    for (const [src, dst] of edges){
        adj.get(src).push(dst);
    }

    const visit = new Set();
    const path = new Set();
    const count = Array.from({ length: n }, () => Array(26).fill(0));
    let res = 0;
    let hasCycle = false;

    const dfs = (node) => {
        if (path.has(node)) {
            hasCycle = true;
            return;
        }

        if (visit.has(node)){
            return;
        }

        visit.add(node);
        path.add(node);

        for (const nei of adj.get(node)){
            dfs(nei);
            if (hasCycle) return;
            for (let c = 0; c < 26; c++){
                count[node][c] = Math.max(count[node][c], count[nei][c]);
            }
        }

        const colorIndex = colors.charCodeAt(node) - 'a'.charCodeAt(0);
        count[node][colorIndex]++;
        res = Math.max(res, count[node][colorIndex]);

        path.delete(node);
    };

    for (let i = 0; i < n; i++){
        if (!visit.has(i)){
            dfs(i);
            if (hasCycle) return -1;
        }
    }
    return res;
};
```

*/
