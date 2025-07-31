Absolutely! Here's a detailed breakdown of **Binary Search in C++**, including:

1. ✅ Standard Binary Search (Iterative)
2. 🔁 Recursive Version
3. 🔄 Variants:

   * First Occurrence
   * Last Occurrence
   * Lower Bound

---

## ✅ 1. Standard Binary Search (Iterative)

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoid overflow

        if (arr[mid] == target) {
            return mid; // found
        } else if (arr[mid] < target) {
            left = mid + 1; // search right half
        } else {
            right = mid - 1; // search left half
        }
    }

    return -1; // not found
}

int main() {
    std::vector<int> data = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;

    int index = binarySearch(data, target);

    if (index != -1)
        std::cout << "Found at index: " << index << "\n";
    else
        std::cout << "Not found\n";

    return 0;
}
```

---

## 🔁 2. Recursive Binary Search

```cpp
int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, target, mid + 1, right);
    else return binarySearchRecursive(arr, target, left, mid - 1);
}
```

---

## 🔄 3. Binary Search Variants

### A. First Occurrence

```cpp
int firstOccurrence(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // keep searching left
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
```

### B. Last Occurrence

```cpp
int lastOccurrence(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // keep searching right
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}
```

### C. Lower Bound (First index where value ≥ target)

```cpp
int lowerBound(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size(), mid;

    while (left < right) {
        mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}
```

---

## 📌 Notes

* All functions assume the array is **sorted in ascending order**.
* You can use `std::lower_bound` or `std::binary_search` in `<algorithm>` as well.

Would you like me to show you how to use the STL equivalents too?

Great! Let's go over how to use **C++ STL (Standard Template Library)** to perform binary search operations efficiently. This can significantly reduce boilerplate code.

---

## ✅ STL Functions for Binary Search

Header needed:

```cpp
#include <algorithm>  // for binary_search, lower_bound, upper_bound
#include <vector>
#include <iostream>
```

### 1. `std::binary_search()`

Checks if the **element exists** in a sorted range.

```cpp
std::vector<int> arr = {2, 4, 6, 8, 10};

if (std::binary_search(arr.begin(), arr.end(), 6)) {
    std::cout << "6 is found\n";
} else {
    std::cout << "6 is not found\n";
}
```

* Returns a **boolean**.
* Does not give the **index**.

---

### 2. `std::lower_bound()`

Finds the **first position** where the value is **not less than** the target (i.e., `≥ target`).

```cpp
auto it = std::lower_bound(arr.begin(), arr.end(), 6);
int index = it - arr.begin();

std::cout << "Lower bound of 6 is at index: " << index << "\n";
```

* If `target` exists, it points to its **first occurrence**.
* If `target` doesn’t exist, it points to the **next greater element**.
* If it returns `arr.end()`, the target is **greater than all elements**.

---

### 3. `std::upper_bound()`

Finds the **first position** where the value is **greater than** the target (`> target`).

```cpp
auto it = std::upper_bound(arr.begin(), arr.end(), 6);
int index = it - arr.begin();

std::cout << "Upper bound of 6 is at index: " << index << "\n";
```

---

### 4. First and Last Occurrence using `lower_bound` & `upper_bound`

To find:

* **First Occurrence**: Use `lower_bound`.
* **Last Occurrence**: Use `upper_bound - 1` (after confirming target exists).

```cpp
int target = 6;
auto first = std::lower_bound(arr.begin(), arr.end(), target);
auto last = std::upper_bound(arr.begin(), arr.end(), target);

if (first != arr.end() && *first == target) {
    std::cout << "First at index: " << (first - arr.begin()) << "\n";
    std::cout << "Last at index: " << (last - arr.begin()) - 1 << "\n";
} else {
    std::cout << "Element not found\n";
}
```

---

## 🧠 Summary of STL Methods

| Function        | Returns                | Purpose                         |
| --------------- | ---------------------- | ------------------------------- |
| `binary_search` | `true` or `false`      | Checks if element exists        |
| `lower_bound`   | Iterator to `≥ target` | First position to insert target |
| `upper_bound`   | Iterator to `> target` | End of range of equal elements  |

---

Would you like a complete STL-based example, or do you want to learn how to use these with custom data types or comparators (e.g., structs, descending order)?
