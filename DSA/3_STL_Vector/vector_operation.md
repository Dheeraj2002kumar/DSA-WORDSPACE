Absolutely! Below is a **complete C++ program** that demonstrates all the commonly used operations of `std::vector` in one place.

---

### ✅ `vector_operations.cpp`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>      // for accumulate
#include <iterator>     // for iterators

using namespace std;

int main() {
    // Declaration & Initialization
    vector<int> v1;                         // Empty vector
    vector<int> v2(5);                      // Size 5, all elements 0
    vector<int> v3(5, 10);                  // Size 5, all elements 10
    vector<int> v4 = {1, 2, 3, 4, 5};       // Initialization list

    // Push & Pop
    v4.push_back(6);
    v4.pop_back();

    // Access
    cout << "v4[0] = " << v4[0] << "\n";
    cout << "v4.at(1) = " << v4.at(1) << "\n";
    cout << "Front = " << v4.front() << ", Back = " << v4.back() << "\n";

    // Size and Capacity
    cout << "Size: " << v4.size() << ", Capacity: " << v4.capacity() << "\n";

    // Iteration
    cout << "Elements in v4: ";
    for (int x : v4) cout << x << " ";
    cout << "\n";

    // Insert and Erase
    v4.insert(v4.begin() + 2, 99);           // Insert 99 at index 2
    v4.erase(v4.begin() + 3);                // Remove element at index 3

    // Sort
    sort(v4.begin(), v4.end());              // Ascending
    reverse(v4.begin(), v4.end());           // Descending

    // Searching
    if (find(v4.begin(), v4.end(), 99) != v4.end())
        cout << "99 found in vector\n";

    // Accumulate (sum)
    int sum = accumulate(v4.begin(), v4.end(), 0);
    cout << "Sum of elements: " << sum << "\n";

    // Resize
    v4.resize(10);                           // Add 0s to make size 10
    v4.resize(3);                            // Trim to 3 elements

    // Swap
    vector<int> v5 = {100, 200};
    v4.swap(v5);

    // Clear
    v5.clear();

    // Empty check
    if (v5.empty()) cout << "v5 is empty\n";

    // Reserve & Shrink
    vector<int> v6;
    v6.reserve(100);                         // Reserve space
    cout << "Capacity after reserve: " << v6.capacity() << "\n";
    v6.push_back(1);
    v6.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << v6.capacity() << "\n";

    // Emplace back
    vector<pair<int, string>> vp;
    vp.emplace_back(1, "one");               // Constructs in place
    vp.push_back(make_pair(2, "two"));       // Makes pair then copies

    cout << "Vector of pairs:\n";
    for (auto& [num, word] : vp)
        cout << num << " - " << word << "\n";

    // 2D vector
    vector<vector<int>> matrix(3, vector<int>(4, 0)); // 3x4 matrix
    matrix[0][1] = 7;
    cout << "matrix[0][1] = " << matrix[0][1] << "\n";

    return 0;
}
```

---

## ✅ Features Demonstrated

* ✅ Declaration, Initialization
* ✅ `push_back`, `pop_back`, `emplace_back`
* ✅ Access: `[]`, `at()`, `front()`, `back()`
* ✅ `insert`, `erase`, `clear`, `resize`, `swap`
* ✅ Iteration (range-based + iterator)
* ✅ Searching (`find`), Sorting, Reversing
* ✅ Accumulate (sum of elements)
* ✅ Capacity Management: `size`, `capacity`, `reserve`, `shrink_to_fit`
* ✅ Multi-dimensional vector (2D vector)

---
