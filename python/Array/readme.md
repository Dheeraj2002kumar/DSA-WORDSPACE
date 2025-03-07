## **Everything About Arrays in JavaScript (Data Structure & Algorithms)**
Arrays are one of the most fundamental data structures in JavaScript. They allow us to store multiple values in a single variable and provide numerous methods to manipulate data efficiently.

---

# **📌 1. What is an Array?**
An **array** in JavaScript is an ordered collection of elements. Each element in an array has a unique index starting from `0`.

### **Example:**
```javascript
let arr = [10, 20, 30, 40, 50];
console.log(arr[0]); // Output: 10
console.log(arr[2]); // Output: 30
```

### **Characteristics of JavaScript Arrays:**
✔ **Dynamic Size** – Unlike arrays in some other languages, JavaScript arrays can grow or shrink dynamically.  
✔ **Heterogeneous Elements** – Arrays can store different data types (numbers, strings, objects, etc.).  
✔ **Zero-based Indexing** – The first element starts at index `0`.

---

# **📌 2. How to Create Arrays in JavaScript**
### **1️⃣ Using Array Literals (Recommended)**
```javascript
let numbers = [1, 2, 3, 4, 5];  // Simple array
let mixed = [1, "hello", true, {name: "Dheeraj"}]; // Different types
```

### **2️⃣ Using `new Array()` Constructor**
```javascript
let arr = new Array(5); // Creates an empty array of length 5
console.log(arr); // [empty × 5]
```

### **3️⃣ Using `Array.of()`**
```javascript
let arr = Array.of(10, 20, 30);
console.log(arr); // [10, 20, 30]
```

### **4️⃣ Using `Array.from()`**
```javascript
let str = "hello";
let arr = Array.from(str);
console.log(arr); // ['h', 'e', 'l', 'l', 'o']
```

---

# **📌 3. Common Array Methods in JavaScript**
## **📍 Adding & Removing Elements**
| **Method**       | **Description**                 | **Example** |
|-----------------|------------------------------|------------|
| `push()`        | Adds element at the **end**  | `arr.push(10)` |
| `pop()`         | Removes element from the **end** | `arr.pop()` |
| `unshift()`     | Adds element at the **beginning** | `arr.unshift(5)` |
| `shift()`       | Removes element from the **beginning** | `arr.shift()` |

### **Example**
```javascript
let arr = [1, 2, 3];
arr.push(4);      // [1, 2, 3, 4]
arr.pop();        // [1, 2, 3]
arr.unshift(0);   // [0, 1, 2, 3]
arr.shift();      // [1, 2, 3]
```

---

## **📍 Looping Through Arrays**
### **1️⃣ Using `for` loop**
```javascript
let arr = [10, 20, 30];
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}
```

### **2️⃣ Using `forEach()`**
```javascript
arr.forEach((value) => console.log(value));
```

### **3️⃣ Using `map()` (Returns a new array)**
```javascript
let newArr = arr.map((num) => num * 2);
console.log(newArr); // [20, 40, 60]
```

---

## **📍 Searching & Filtering**
| **Method**    | **Description** | **Example** |
|--------------|---------------|------------|
| `indexOf()`  | Finds the index of an element | `arr.indexOf(30)` |
| `includes()` | Checks if value exists | `arr.includes(20)` |
| `find()`     | Finds first match | `arr.find(x => x > 25)` |
| `filter()`   | Filters values | `arr.filter(x => x > 15)` |

### **Example**
```javascript
let arr = [10, 20, 30, 40];

console.log(arr.indexOf(30)); // 2
console.log(arr.includes(50)); // false
console.log(arr.find(x => x > 25)); // 30
console.log(arr.filter(x => x > 20)); // [30, 40]
```

---

## **📍 Sorting & Reversing**
| **Method**     | **Description** | **Example** |
|--------------|----------------|------------|
| `sort()`    | Sorts array (Lexicographically by default) | `arr.sort()` |
| `reverse()` | Reverses an array | `arr.reverse()` |

### **Sorting Numbers**
```javascript
let nums = [4, 2, 9, 1, 5];
nums.sort((a, b) => a - b);  // Ascending order
console.log(nums); // [1, 2, 4, 5, 9]
```

---

# **📌 4. Array Algorithms**
## **1️⃣ Searching Algorithms**
### **🔹 Linear Search (O(n))**
```javascript
function linearSearch(arr, target) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === target) return i;
    }
    return -1;
}
console.log(linearSearch([10, 20, 30, 40], 30)); // 2
```

### **🔹 Binary Search (O(log n))**
✅ Works **only** on **sorted** arrays.
```javascript
function binarySearch(arr, target) {
    let left = 0, right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
console.log(binarySearch([10, 20, 30, 40], 30)); // 2
```

---

## **2️⃣ Sorting Algorithms**
### **🔹 Bubble Sort (O(n²))**
```javascript
function bubbleSort(arr) {
    let n = arr.length;
    for (let i = 0; i < n - 1; i++) {
        for (let j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
    return arr;
}
console.log(bubbleSort([5, 3, 8, 1, 2])); // [1, 2, 3, 5, 8]
```

### **🔹 Quick Sort (O(n log n))**
```javascript
function quickSort(arr) {
    if (arr.length <= 1) return arr;
    let pivot = arr[arr.length - 1];
    let left = arr.filter(x => x < pivot);
    let right = arr.filter(x => x > pivot);
    return [...quickSort(left), pivot, ...quickSort(right)];
}
console.log(quickSort([5, 3, 8, 1, 2])); // [1, 2, 3, 5, 8]
```

---

# **📌 5. When to Use Arrays?**
✔ **When you need fast access by index** – `O(1)` lookup time.  
✔ **When order matters** – Arrays maintain insertion order.  
✔ **When memory efficiency is important** – Arrays are more compact than linked lists.  

---

# **📌 Conclusion**
- JavaScript arrays are **dynamic and versatile**.
- Various **built-in methods** make them powerful.
- **Searching & Sorting algorithms** can optimize performance.
- Arrays are used in **real-world projects** like dashboards, e-commerce sites, and gaming leaderboards.

---

Here’s everything about **Arrays in Python**, including how to create, manipulate, and implement common algorithms.

---

# **📌 1. What is an Array in Python?**
Python **does not have built-in support** for arrays like JavaScript. Instead, it provides:
- **Lists** (Dynamic, flexible, and widely used)
- **`array` module** (Efficient for numerical data)
- **NumPy Arrays** (Faster and optimized for numerical computing)

---

# **📌 2. How to Create Arrays in Python**
### **1️⃣ Using Lists (Most Common)**
```python
arr = [10, 20, 30, 40]
print(arr[0])  # Output: 10
```

### **2️⃣ Using `array` Module (Type-Specific Arrays)**
```python
import array
arr = array.array('i', [10, 20, 30, 40])  # 'i' stands for integer
print(arr[0])  # Output: 10
```

### **3️⃣ Using NumPy Arrays (Best for Performance)**
```python
import numpy as np
arr = np.array([10, 20, 30, 40])
print(arr[0])  # Output: 10
```

---

# **📌 3. Common Array Operations**
## **📍 Adding & Removing Elements**
| **Method**        | **Python List Equivalent**    | **Example** |
|------------------|---------------------------|------------|
| `push()` (JS)   | `append()`                 | `arr.append(50)` |
| `pop()` (JS)    | `pop()`                     | `arr.pop()` |
| `unshift()` (JS)| `insert(0, value)`         | `arr.insert(0, 5)` |
| `shift()` (JS)  | `pop(0)`                   | `arr.pop(0)` |

### **Example**
```python
arr = [1, 2, 3]
arr.append(4)  # [1, 2, 3, 4]
arr.pop()      # [1, 2, 3]
arr.insert(0, 0)  # [0, 1, 2, 3]
arr.pop(0)     # [1, 2, 3]
```

---

## **📍 Looping Through Arrays**
### **1️⃣ Using `for` Loop**
```python
arr = [10, 20, 30]
for num in arr:
    print(num)
```

### **2️⃣ Using `map()`**
```python
arr = [10, 20, 30]
new_arr = list(map(lambda x: x * 2, arr))
print(new_arr)  # [20, 40, 60]
```

---

## **📍 Searching & Filtering**
| **JS Method** | **Python Equivalent** | **Example** |
|--------------|----------------------|------------|
| `indexOf()` | `index()` | `arr.index(30)` |
| `includes()` | `in` | `30 in arr` |
| `find()` | `next(filter(...))` | `next(x for x in arr if x > 25)` |
| `filter()` | `filter()` | `list(filter(lambda x: x > 15, arr))` |

### **Example**
```python
arr = [10, 20, 30, 40]

print(arr.index(30))  # Output: 2
print(50 in arr)  # Output: False
print(next(x for x in arr if x > 25))  # Output: 30
print(list(filter(lambda x: x > 20, arr)))  # Output: [30, 40]
```

---

## **📍 Sorting & Reversing**
| **JS Method** | **Python Equivalent** | **Example** |
|--------------|----------------------|------------|
| `sort()` | `sort()` | `arr.sort()` |
| `reverse()` | `reverse()` | `arr.reverse()` |

### **Sorting Numbers**
```python
nums = [4, 2, 9, 1, 5]
nums.sort()  # Ascending order
print(nums)  # Output: [1, 2, 4, 5, 9]
```

---

# **📌 4. Array Algorithms**
## **1️⃣ Searching Algorithms**
### **🔹 Linear Search (O(n))**
```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

print(linear_search([10, 20, 30, 40], 30))  # Output: 2
```

### **🔹 Binary Search (O(log n))**
✅ Works **only** on **sorted** arrays.
```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

print(binary_search([10, 20, 30, 40], 30))  # Output: 2
```

---

## **2️⃣ Sorting Algorithms**
### **🔹 Bubble Sort (O(n²))**
```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

print(bubble_sort([5, 3, 8, 1, 2]))  # Output: [1, 2, 3, 5, 8]
```

### **🔹 Quick Sort (O(n log n))**
```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[-1]
    left = [x for x in arr[:-1] if x <= pivot]
    right = [x for x in arr[:-1] if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)

print(quick_sort([5, 3, 8, 1, 2]))  # Output: [1, 2, 3, 5, 8]
```

---

# **📌 5. When to Use Arrays in Python?**
✔ **When you need fast access by index** – `O(1)` lookup time.  
✔ **When order matters** – Lists maintain insertion order.  
✔ **When memory efficiency is important** – Arrays are more compact than linked lists.  

---

# **📌 Conclusion**
- Python **lists** are the most commonly used array-like structure.
- The **`array` module** and **NumPy** are better for performance.
- **Built-in methods** like `sort()`, `index()`, and `filter()` simplify array manipulation.
- **Efficient searching & sorting algorithms** are crucial for performance.

---