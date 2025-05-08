# Intuition

The problem is essentially a shortest-path problem on a grid, where each cell has a time constraint for when it can be entered, and the cost to move depends on the coordinates of the destination. My first thought was to use Dijkstra's algorithm since it handles variable path costs and works well for grid traversal problems where the "earliest arrival time" is required.

# Approach

We use Dijkstra’s algorithm to find the minimum time to reach the bottom-right cell `(m-1, n-1)` from the top-left cell `(0, 0)`. Each cell is treated as a graph node, and we use a min-heap (priority queue) to always expand the node with the smallest current time.

- We initialize a 2D `result` array to track the minimum time to reach each cell.
- From each cell, we attempt to move in the four cardinal directions (up, down, left, right).
- The cost to move into a new cell depends on its coordinates: it's `2` if the sum of the indices is even, otherwise `1`.
- If arriving at a cell before its allowed `moveTime`, we must wait there.
- The final answer is the minimum time it takes to reach the bottom-right cell.

# Complexity

- **Time complexity:**  
  $$O(m \cdot n \cdot \log(m \cdot n))$$  
  Each cell can be pushed to the priority queue once with better cost, and the priority queue operations take log time.

- **Space complexity:**  
  $$O(m \cdot n)$$  
  We store the minimum arrival times in a 2D matrix and use a priority queue of up to \(m \cdot n\) elements.

# Code

```cpp []
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, pair<int, int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();
            if (i == m-1 && j == n-1){
                return currTime;
            }

            for (auto &dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n){
                    int moveCost = (i_ + j_) % 2 == 0 ? 2 : 1;
                    int wait = max(moveTime[i_][j_] - currTime, 0);
                    int arrTime = currTime + wait + moveCost;

                    if(result[i_][j_] > arrTime){
                        result[i_][j_] = arrTime;
                        pq.push({arrTime, {i_, j_}});
                    }
                }
            }

        }
        return -1;
    }
};
```
---

# Intuition
The problem requires navigating a 2D grid with constraints on when each cell can be entered, as well as variable movement costs based on the number of steps taken. My initial intuition was that this is similar to a shortest path problem where the cost is not just distance but also depends on time and cell-specific rules. Since the path cost changes dynamically and earlier arrival doesn't always mean better, Dijkstra’s algorithm was a natural choice using a min-heap.

# Approach
We use a variation of Dijkstra's algorithm with a custom `MinHeap` implementation to always expand the lowest-cost path first.

- Each state in the queue is represented as `[cost, i, j, step]`:
  - `cost`: total time spent to reach this cell.
  - `i`, `j`: current cell position.
  - `step`: number of steps taken so far (used to determine movement cost).
- Movement cost alternates: 1 for even steps, 2 for odd steps.
- If a cell is not available for entry until a future time (defined in `moveTime[i][j]`), the algorithm waits.
- A memoization grid `memo` tracks the minimum time to reach each cell, and pruning is done by skipping any path that has a worse cost than already computed.

The first time we reach the bottom-right cell `(m-1, n-1)`, we return the current cost.

# Complexity
- **Time complexity:**  
  $$O(m \cdot n \cdot \log(m \cdot n))$$  
  Each cell may be visited multiple times but typically bounded by a few paths. The `MinHeap` handles insertion and deletion in \( \log N \), where \( N \) is the size of the heap.

- **Space complexity:**  
  $$O(m \cdot n)$$  
  Space is used for the memoization matrix and the heap (in the worst case, it can contain all cells).

# Code
```javascript []
/**
 * @param {number[][]} moveTime
 * @return {number}
 */
var minTimeToReach = function(moveTime) {
    const m = moveTime.length;
    const n = moveTime[0].length;
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    const memo = Array.from({ length: m }, () => new Array(n).fill(Number.MAX_VALUE));
    const queue = new MinHeap ([0, 0, 0, 0]);

    while (!queue.isEmpty()) {
        const [cost, i, j, step] = queue.dequeue();

        if (cost > memo[i][j]) continue;
        if (i === m - 1 && j === n - 1) return cost;

        for (const [row, col] of directions) {
            const x = i + row;
            const y = j + col;

            if (x < 0 || x >= m || y < 0 || y >= n) continue;

            const stepCost = step % 2 === 0 ? 1 : 2;
            const newCost = cost + stepCost + Math.max(0, moveTime[x][y] - cost);

            if (memo[x][y] > newCost) {
                memo[x][y] = newCost;
                queue.enqueue([newCost, x, y, step + 1]);
            }

        }
    }

    return -1;
};

class MinHeap {
    constructor(tuple) {
        this.heap = [tuple];
    }

    parent(index) {
        return Math.floor((index - 1) / 2);
    }

    leftChild(index) {
        return 2 * index + 1;
    }

    rightChild(index) {
        return 2 * index + 2;
    }

    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }

    enqueue(tuple) {
        this.heap.push(tuple);
        this.bubbleUp(this.heap.length - 1);
    }

    dequeue() {
        if (this.heap.length === 1) return this.heap.pop();
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return root;
    }

    bubbleUp(i) {
        while (i > 0 && this.heap[this.parent(i)][0] > this.heap[i][0]) {
            this.swap(i, this.parent(i));
            i = this.parent(i);
        }
    }

    bubbleDown(i) {
        let smallest = i;
        const left = this.leftChild(i);
        const right = this.rightChild(i);

        if (left < this.heap.length && this.heap[left][0] < this.heap[smallest][0]) {
            smallest = left;
        }

        if (right < this.heap.length && this.heap[right][0] < this.heap[smallest][0]) {
            smallest = right;
        }

        if (smallest !== i) {
            this.swap(i, smallest);
            this.bubbleDown(smallest);
        }
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    peek() {
        return this.heap[0];
    }

    size () {
        return this.heap.length;
    }
}
```