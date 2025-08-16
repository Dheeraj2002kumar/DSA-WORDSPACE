Sure! The **Standard Template Library (STL)** in C++ is a powerful set of C++ template classes that provide **generic** and **reusable** implementations of common data structures and algorithms. STL is part of the C++ Standard Library and helps write code that is:

* Efficient
* Type-safe
* Easy to maintain
* Highly reusable

---

## 🔷 1. **STL Components**

STL is made up of **four** major components:

| Component  | Description                                |
| ---------- | ------------------------------------------ |
| Containers | Data structures (like arrays, lists, maps) |
| Algorithms | Functions (like sort, search, etc.)        |
| Iterators  | Objects used to traverse containers        |
| Functors   | Objects that can be used like functions    |

---

## 🔶 2. **STL Containers**

Containers store collections of data. They are broadly classified into:

### A. **Sequence Containers**

Maintain the order of insertion.

| Container      | Description                 |
| -------------- | --------------------------- |
| `vector`       | Dynamic array               |
| `list`         | Doubly linked list          |
| `deque`        | Double-ended queue          |
| `array`        | Fixed-size array (C++11+)   |
| `forward_list` | Singly linked list (C++11+) |

### B. **Associative Containers**

Use **keys** to store data, sorted automatically.

| Container  | Description                     |
| ---------- | ------------------------------- |
| `set`      | Unique keys, sorted             |
| `multiset` | Duplicate keys allowed          |
| `map`      | Key-value pairs, unique keys    |
| `multimap` | Key-value pairs, duplicate keys |

### C. **Unordered Containers** (C++11+)

Use **hash tables** for faster access (not sorted).

| Container            | Description            |
| -------------------- | ---------------------- |
| `unordered_set`      | Unique keys            |
| `unordered_multiset` | Duplicate keys         |
| `unordered_map`      | Key-value, unique keys |
| `unordered_multimap` | Key-value, duplicates  |

---

## 🔷 3. **STL Iterators**

Iterators act like pointers and help traverse containers.

### Types of Iterators:

| Type             | Description                                        |
| ---------------- | -------------------------------------------------- |
| Input Iterator   | Read-only, single pass (e.g., `istream_iterator`)  |
| Output Iterator  | Write-only, single pass (e.g., `ostream_iterator`) |
| Forward Iterator | Read/write, multiple passes                        |
| Bidirectional    | Move both forward/backward (e.g., `list`)          |
| Random Access    | All operations (e.g., `vector`, `deque`)           |

Most common iterators:

```cpp
vector<int>::iterator it;
auto it = v.begin(); // modern way
```

---

## 🔶 4. **STL Algorithms**

Defined in `<algorithm>` header. They work on ranges (using iterators).

### Common Algorithms:

| Algorithm         | Description                  |
| ----------------- | ---------------------------- |
| `sort()`          | Sorts range                  |
| `reverse()`       | Reverses range               |
| `count()`         | Counts elements              |
| `find()`          | Finds element                |
| `binary_search()` | Requires sorted data         |
| `lower_bound()`   | First >= value (sorted)      |
| `upper_bound()`   | First > value (sorted)       |
| `accumulate()`    | Sum range (from `<numeric>`) |

Example:

```cpp
#include <algorithm>
sort(vec.begin(), vec.end());
```

---

## 🔷 5. **Functors (Function Objects)**

These are classes that **overload the `()` operator**.

```cpp
struct Square {
    int operator()(int x) const {
        return x * x;
    }
};
```

Used in algorithms:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

---

## 🔶 6. **Custom Comparators**

To sort or organize elements in custom ways.

### Example:

```cpp
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

sort(v.begin(), v.end(), comp);
```

---

## 🔷 7. **Utility Headers**

* `<utility>` → `pair`, `make_pair`
* `<tuple>` → `tuple`, `make_tuple`, `get<>`
* `<functional>` → `greater`, `less`, etc.
* `<numeric>` → `accumulate`

---

## 🔶 8. **Common Usage Examples**

### Vector Example:

```cpp
vector<int> v = {4, 2, 5, 3};
sort(v.begin(), v.end());
for (int x : v) cout << x << " ";
```

### Map Example:

```cpp
map<string, int> m;
m["apple"] = 2;
m["banana"] = 3;
for (auto [k, v] : m) cout << k << " = " << v << "\n";
```

---

## 🔷 9. **Time Complexity and Performance**

STL containers are **well-optimized**, but you must know their complexities:

| Container       | Insertion            | Deletion | Access   |
| --------------- | -------------------- | -------- | -------- |
| `vector`        | O(1) amortized (end) | O(n)     | O(1)     |
| `list`          | O(1)                 | O(1)     | O(n)     |
| `map`           | O(log n)             | O(log n) | O(log n) |
| `unordered_map` | O(1) average         | O(1)     | O(1)     |
| `set`           | O(log n)             | O(log n) | O(log n) |

---

## ✅ STL Advantages

* **Code reuse** and abstraction
* **Faster development**
* **Efficiency** (performance-optimized)
* **Generic programming** using templates

---

## ⚠️ STL Tips

* Be careful with **iterators invalidation** (e.g., when modifying containers).
* Know the difference between `emplace` and `insert` (emplace is usually faster).
* Use `reserve()` with `vector` to avoid reallocations if size is known.

---

Would you like a cheatsheet or some practice problems for STL as well?


Great! Here's a **C++ STL Cheatsheet** followed by **practice problems** to help you master it.

---

# ✅ **C++ STL Cheatsheet**

---

## 📦 Containers

### 1. `vector<T>`

* Dynamic array

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
sort(v.begin(), v.end());
```

---

### 2. `deque<T>`

* Double-ended vector

```cpp
deque<int> d;
d.push_front(1); d.push_back(2);
```

---

### 3. `list<T>`

* Doubly linked list

```cpp
list<int> l;
l.push_back(10); l.push_front(5);
```

---

### 4. `stack<T>`

* LIFO (based on deque)

```cpp
stack<int> s;
s.push(1); s.top(); s.pop();
```

---

### 5. `queue<T>`

* FIFO

```cpp
queue<int> q;
q.push(1); q.front(); q.pop();
```

---

### 6. `priority_queue<T>`

* Max-heap (default)

```cpp
priority_queue<int> pq;
pq.push(10); pq.top(); pq.pop();
```

#### Min-heap:

```cpp
priority_queue<int, vector<int>, greater<int>> min_pq;
```

---

### 7. `set<T>` / `multiset<T>`

* Sorted unique / duplicates allowed

```cpp
set<int> s;
s.insert(5); s.erase(5); s.count(5);
```

---

### 8. `map<Key, Value>` / `multimap`

* Sorted key-value store

```cpp
map<string, int> m;
m["apple"] = 3;
```

---

### 9. `unordered_set`, `unordered_map`

* Same as above, but **faster (average O(1))** and **not sorted**

---

## 🔁 Iterators

### Basic Iteration

```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### Range-Based For Loop

```cpp
for (int x : v) cout << x << " ";
```

---

## 🔧 Algorithms (from `<algorithm>`)

| Function             | Purpose                        |
| -------------------- | ------------------------------ |
| `sort()`             | Sort elements                  |
| `reverse()`          | Reverse range                  |
| `find()`             | Linear search                  |
| `count()`            | Count occurrences              |
| `accumulate()`       | Sum (needs `<numeric>`)        |
| `lower_bound()`      | First element ≥ val (sorted)   |
| `upper_bound()`      | First element > val (sorted)   |
| `binary_search()`    | Check if value exists (sorted) |
| `next_permutation()` | Next lexicographic permutation |

---

## ➕ Pairs and Tuples

```cpp
pair<int, int> p = {1, 2};
cout << p.first << " " << p.second;

tuple<int, char, string> t = {1, 'a', "hello"};
get<0>(t); // 1
```

---

## 🚀 STL Time Complexities

| Operation         | `vector` | `list` | `set/map` | `unordered_map` |
| ----------------- | -------- | ------ | --------- | --------------- |
| Insert (end)      | O(1)     | O(1)   | O(log n)  | O(1) avg        |
| Insert (anywhere) | O(n)     | O(1)   | O(log n)  | O(1) avg        |
| Access by index   | O(1)     | O(n)   | O(log n)  | O(1) avg        |
| Search            | O(n)     | O(n)   | O(log n)  | O(1) avg        |

---

# 🧠 Practice Problems (by difficulty)

---

## 🟢 Beginner

1. **Reverse an array using vector**
2. **Sort an array of integers**
3. **Count frequency of elements using `map`**
4. **Find max and min in a list**

---

## 🟡 Intermediate

5. **Top K frequent elements (priority\_queue + map)**
6. **Implement LRU Cache (using `list` + `unordered_map`)**
7. **Find first element ≥ X using `lower_bound`**
8. **Store and sort pairs by second value**

---

## 🔴 Advanced

9. **Dijkstra’s Algorithm (set/priority\_queue)**
10. **Custom sorting using comparator (e.g., sort strings by length)**
11. **Interval merging using `pair` and `sort`**
12. **Trie implementation with unordered\_map**

---

## ✅ Suggested Practice Platforms:

* [LeetCode](https://leetcode.com)
* [Codeforces](https://codeforces.com)
* [AtCoder](https://atcoder.jp)
* [GeeksforGeeks STL problems](https://www.geeksforgeeks.org/tag/stl/)

---

Would you like me to generate a few **custom problems with solutions** or templates using STL?
