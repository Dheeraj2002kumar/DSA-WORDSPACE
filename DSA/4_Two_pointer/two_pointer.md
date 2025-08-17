Sure! Let’s go over **two pointers** in C++ in detail.

---

## 🔹 What Is the Two Pointer Technique?

The **two pointer technique** is a commonly used method in C++ (and other languages) to solve problems involving **arrays or strings**. It involves using **two indices (pointers)** to iterate through a data structure, usually with the goal of:

* Finding a pair that satisfies some condition (like a sum).
* Moving from both ends towards the middle.
* Comparing or merging elements.
* Eliminating unnecessary elements.

---

## 🔸 Why Use Two Pointers?

* It’s **more efficient** than nested loops in many cases.
* Reduces time complexity from **O(n²)** to **O(n)** for many problems.
* Makes solutions **clean and easy to understand**.

---

## 🔹 Example Use Cases

### ✅ Example 1: Finding a Pair with a Given Sum in a Sorted Array

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            cout << "Pair: (" << arr[left] << ", " << arr[right] << ")\n";
            return true;
        } else if (sum < target) {
            left++;  // Move to larger value
        } else {
            right--; // Move to smaller value
        }
    }

    return false;
}

int main() {
    vector<int> arr = {1, 3, 4, 5, 7, 10, 11};
    int target = 9;
    hasPairWithSum(arr, target);
    return 0;
}
```

### 🔍 Explanation

* We use two pointers: `left` starting at beginning, `right` at end.
* We calculate `sum = arr[left] + arr[right]`.
* If the sum matches the target, we return true.
* If the sum is too small, we need a larger value → increment `left`.
* If the sum is too large, we need a smaller value → decrement `right`.

**Time complexity: O(n)**
**Space complexity: O(1)**

---

### ✅ Example 2: Removing Duplicates from a Sorted Array (In-place)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int slow = 0;  // slow pointer

    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1; // length of the unique array
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int length = removeDuplicates(nums);

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
```

### 🔍 Explanation

* `slow` keeps track of the last unique element.
* `fast` scans ahead to find a new unique element.
* When found, increment `slow` and copy the value there.
* This modifies the array **in-place**.

**Time complexity: O(n)**
**Space complexity: O(1)**

---

## 🔹 Types of Two Pointer Movement

| Pointer Usage | Description                                 | Common Problems                      |
| ------------- | ------------------------------------------- | ------------------------------------ |
| Start + End   | Move inward from both ends                  | Sum problems, Palindromes            |
| Both Forward  | One fast, one slow                          | Removing duplicates, cycle detection |
| One Fixed     | One pointer scans ahead, the other is fixed | Sliding window-type logic            |

---

## 🔸 Summary

* **Two Pointers** = Using two indices to iterate and process arrays/strings efficiently.
* Common in **searching**, **sorting**, **merging**, and **optimization** problems.
* Reduces complexity and increases performance compared to brute-force approaches.

---

