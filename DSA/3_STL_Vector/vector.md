Absolutely! Here's a **comprehensive guide to `vector` in C++**, one of the most commonly used containers from the Standard Template Library (STL).

---

# 📦 `vector` in C++

A `vector` in C++ is a **dynamic array** — it can **grow or shrink in size** at runtime. It provides **random access**, and supports most array operations, but with additional flexibility.

---

## 🧩 Key Characteristics

| Feature           | Description                                            |
| ----------------- | ------------------------------------------------------ |
| Dynamic resizing  | Automatically resizes as elements are added or removed |
| Contiguous memory | Elements are stored like an array                      |
| Random access     | Supports direct access via `[]` or `at()`              |
| STL compatible    | Works with algorithms, iterators, etc.                 |

---

## ✅ Header & Declaration

```cpp
#include <vector>
using namespace std;

vector<int> v;                // Empty vector
vector<int> v(5);             // 5 elements initialized to 0
vector<int> v(5, 10);         // 5 elements, all = 10
vector<int> v2 = {1, 2, 3};   // Initialization list
```

---

## 🔨 Basic Operations

### Add elements

```cpp
v.push_back(10);     // Adds 10 at end
```

### Remove elements

```cpp
v.pop_back();        // Removes last element
```

### Access elements

```cpp
int x = v[0];        // No bounds check
int y = v.at(0);     // Throws exception if out of bounds
```

### Size & Capacity

```cpp
v.size();            // Number of elements
v.capacity();        // Allocated storage
v.empty();           // true if empty
```

### Resize

```cpp
v.resize(10);        // Resizes to 10 (adds 0s if needed)
```

---

## ♻️ Iterating Over Vector

```cpp
// Traditional
for (int i = 0; i < v.size(); ++i)
    cout << v[i];

// Range-based
for (int x : v)
    cout << x;

// Iterator
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it;
```

---

## 🧹 Modifying Vector

### Inserting Elements

```cpp
v.insert(v.begin() + 2, 99);       // Insert 99 at index 2
```

### Erasing Elements

```cpp
v.erase(v.begin() + 2);            // Remove element at index 2
v.erase(v.begin() + 1, v.begin() + 4); // Remove range [1, 4)
```

### Clear

```cpp
v.clear();         // Removes all elements
```

---

## ⚙️ Sorting

```cpp
sort(v.begin(), v.end());                 // Ascending
sort(v.rbegin(), v.rend());               // Descending

// Custom comparator
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;   // Descending
});
```

---

## 🛠️ Common Member Functions

| Function             | Description                    |
| -------------------- | ------------------------------ |
| `push_back(val)`     | Add element to end             |
| `pop_back()`         | Remove last element            |
| `insert(pos, val)`   | Insert at specific position    |
| `erase(pos)`         | Remove element at position     |
| `clear()`            | Remove all elements            |
| `resize(n)`          | Resize vector                  |
| `size()`             | Get number of elements         |
| `capacity()`         | Get current allocated capacity |
| `empty()`            | Check if vector is empty       |
| `shrink_to_fit()`    | Reduce capacity to match size  |
| `front()` / `back()` | Access first / last element    |
| `begin()` / `end()`  | Get iterators                  |

---

## 🔄 Capacity Management

```cpp
v.reserve(1000);    // Reserve capacity for 1000 elements
v.shrink_to_fit();  // Reduce capacity to size
```

---

## 🔂 Swapping Vectors

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5};

a.swap(b);         // Now a = {4, 5}, b = {1, 2, 3}
```

---

## 🧠 Behind the Scenes

* Vectors use **doubling strategy**:

  * When capacity is exceeded, vector doubles its size.
* Time complexities:

  * `push_back()` — **O(1)** amortized
  * `insert()` — **O(n)** (due to shifting)
  * `erase()` — **O(n)** (due to shifting)
  * Random access — **O(1)**

---

## 🚫 When Not to Use `vector`

Use `list`, `deque`, or other containers when:

* Frequent insertions/removals at **beginning or middle** (costly in vector).
* Predictable memory layout isn’t needed.

---

## 💡 Tips

* Use `reserve()` if you know the size in advance (reduces reallocations).
* Use `emplace_back(args...)` instead of `push_back(obj)` to construct in-place.
* For multi-dimensional vector:

  ```cpp
  vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 initialized to 0
  ```

---

## 📌 Example Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {4, 1, 3, 2};
    v.push_back(5);
    sort(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";
}
```

**Output:**

```
1 2 3 4 5
```

---

Would you like:

* A **visual representation** of how vector grows?
* A **set of vector-based coding problems** with solutions?
* An explanation of **`emplace_back` vs `push_back`**?


Great! Let’s go step by step:

---

# 📊 **1. Visual Representation: How `vector` Grows Internally**

When using a `vector`, its **capacity** (allocated memory) is usually **greater than or equal to** its **size** (number of elements). Here's how dynamic resizing works under the hood:

---

### 🔁 `vector` Growth Example

Suppose you start with an empty vector:

```cpp
vector<int> v;
```

Then you do this:

```cpp
for (int i = 1; i <= 8; i++) {
    v.push_back(i);
    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
}
```

🧠 **Typical Output (varies by implementation):**

```
Size: 1, Capacity: 1
Size: 2, Capacity: 2
Size: 3, Capacity: 4
Size: 4, Capacity: 4
Size: 5, Capacity: 8
Size: 6, Capacity: 8
Size: 7, Capacity: 8
Size: 8, Capacity: 8
```

🎯 **Observation**:

* When capacity is full, vector **doubles** its capacity to accommodate more elements.
* Doubling gives **amortized O(1)** insertion time.

🧠 **`reserve(n)`** prevents repeated reallocations by allocating memory upfront.

---

# 🆚 **2. `emplace_back()` vs `push_back()`**

| Function                | Description                        |
| ----------------------- | ---------------------------------- |
| `push_back(obj)`        | Copies or moves an existing object |
| `emplace_back(args...)` | Constructs the object **in place** |

### Example:

```cpp
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
};

vector<Person> people;

people.push_back(Person("Alice", 30));      // Creates, then copies
people.emplace_back("Bob", 25);             // Constructs directly in vector
```

✅ **`emplace_back()` is faster** and avoids unnecessary copies.

---

# 💡 Use `emplace_back()` when:

* You're constructing objects directly inside the vector.
* You want better performance with complex types (like `pair`, `struct`, etc).

---

# 🧪 **3. Vector-Based Coding Problems (with Solutions)**

---

## 🔹 Problem 1: **Remove Duplicates from Sorted Vector**

**Input:** `v = {1, 1, 2, 2, 3}`
**Output:** `v = {1, 2, 3}`

```cpp
vector<int> v = {1, 1, 2, 2, 3};
v.erase(unique(v.begin(), v.end()), v.end());
```

---

## 🔹 Problem 2: **Find K Largest Elements**

**Input:** `v = {7, 4, 6, 3, 9, 1}`, `k = 3`
**Output:** `9 7 6`

```cpp
vector<int> v = {7, 4, 6, 3, 9, 1};
int k = 3;
nth_element(v.begin(), v.begin() + k, v.end(), greater<int>());
for (int i = 0; i < k; i++)
    cout << v[i] << " ";
```

---

## 🔹 Problem 3: **Two Sum (Brute Force)**

**Input:** `v = {2, 7, 11, 15}`, target = 9
**Output:** `0 1` (because 2 + 7 = 9)

```cpp
vector<int> v = {2, 7, 11, 15};
int target = 9;

for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
        if (v[i] + v[j] == target) {
            cout << i << " " << j;
            break;
        }
    }
}
```

> ✅ More efficient with hash map, but this is simple vector-only logic.

---

## 🔹 Problem 4: **Rotate Vector Right by K Steps**

**Input:** `v = {1, 2, 3, 4, 5, 6, 7}`, k = 3
**Output:** `5 6 7 1 2 3 4`

```cpp
vector<int> v = {1, 2, 3, 4, 5, 6, 7};
int k = 3;
k = k % v.size();
reverse(v.begin(), v.end());
reverse(v.begin(), v.begin() + k);
reverse(v.begin() + k, v.end());
```

---

# 🚀 Bonus: Multi-dimensional Vector (2D Vector)

```cpp
int rows = 3, cols = 4;
vector<vector<int>> matrix(rows, vector<int>(cols, 0));
```

Access like:

```cpp
matrix[0][1] = 5;
```

---

