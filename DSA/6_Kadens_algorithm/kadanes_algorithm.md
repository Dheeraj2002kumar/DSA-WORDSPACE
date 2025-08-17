Sure! Let's go over **Kadane’s Algorithm** in **C++**, with full explanation and examples.

---

## 🔹 What Is Kadane’s Algorithm?

**Kadane’s Algorithm** is a famous algorithm used to find the:

> **"Maximum sum of a contiguous subarray"**
> — in **O(n)** time.

This problem is also known as the **"Maximum Subarray Problem"** and often appears in interviews and coding contests.

---

## 🔸 Example Problem

**Given:**
`arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}`

**Goal:**
Find the contiguous subarray (with at least one number) which has the **largest sum**.

✅ Answer:
`[4, -1, 2, 1]` → Sum = **6**

---

## 🔹 Intuition Behind Kadane’s Algorithm

The idea is simple:

* Keep **adding elements** while the sum is **positive**.
* If the current sum becomes **negative**, it will not help the future subarrays → **reset it to 0**.
* Keep track of the **maximum sum** found so far.

---

## 🔸 Step-by-Step Logic

1. Initialize two variables:

   * `maxSum = INT_MIN` → stores overall maximum
   * `currentSum = 0`   → current running sum

2. Loop through the array:

   * Add the current element to `currentSum`
   * Update `maxSum` if `currentSum` is greater
   * If `currentSum` becomes negative → reset it to 0

---

## 🔹 C++ Code: Kadane's Algorithm

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(vector<int>& arr) {
    int maxSum = INT_MIN; // Initialize to smallest possible integer
    int currentSum = 0;

    for (int num : arr) {
        currentSum += num;

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        if (currentSum < 0) {
            currentSum = 0; // Reset when sum is negative
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = kadane(arr);
    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}
```

### 🔍 Output:

```
Maximum Subarray Sum: 6
```

---

## 🔸 Visual Walkthrough (for arr = \[-2,1,-3,4,-1,2,1,-5,4])

| i | arr\[i] | currentSum | maxSum |
| - | ------- | ---------- | ------ |
| 0 | -2      | -2         | -2     |
| 1 | 1       | 1          | 1      |
| 2 | -3      | -2         | 1      |
| 3 | 4       | 4          | 4      |
| 4 | -1      | 3          | 4      |
| 5 | 2       | 5          | 5      |
| 6 | 1       | 6          | 6      |
| 7 | -5      | 1          | 6      |
| 8 | 4       | 5          | 6      |

✅ Final maxSum = 6

---

## 🔹 Edge Case: All Negative Numbers

If the array is like `{-3, -1, -2}`, you still want to return the **largest single element**, not 0.

Kadane handles it correctly because:

* `maxSum` starts at `INT_MIN`
* Even if `currentSum` is never positive, the max of all negatives will be returned

---

## 🔸 Variant: Printing the Subarray

To print the actual subarray, track **start and end indices**:

```cpp
int kadaneWithSubarray(vector<int>& arr) {
    int maxSum = INT_MIN, currentSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Maximum Subarray: ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return maxSum;
}
```

---

## ✅ Summary

| Feature              | Details                        |
| -------------------- | ------------------------------ |
| Problem Solved       | Max sum of contiguous subarray |
| Time Complexity      | **O(n)**                       |
| Space Complexity     | **O(1)**                       |
| Works With Negatives | ✅ Yes                          |
| Tracks Subarray      | ✅ With extra variables         |

---

Let me know if you'd like to see Kadane's used in 2D arrays or circular arrays — both are common advanced variants.
