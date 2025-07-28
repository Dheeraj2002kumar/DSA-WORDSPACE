Here's how you can implement **Selection Sort** in JavaScript:

### ✅ Selection Sort in JavaScript

```javascript
function selectionSort(arr) {
    const n = arr.length;

    for (let i = 0; i < n - 1; i++) {
        // Assume the current index is the smallest
        let minIndex = i;

        // Find the index of the smallest element in the remaining array
        for (let j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex !== i) {
            [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
        }
    }

    return arr;
}

// Example usage
const array = [64, 25, 12, 22, 11];
console.log("Sorted array:", selectionSort(array));  // Output: [11, 12, 22, 25, 64]
```

---

### 📌 How Selection Sort Works:

1. Repeatedly find the minimum element from the unsorted part of the array.
2. Swap it with the first unsorted element.
3. Move the boundary of the sorted part one step forward.

---

### 🔍 Time Complexity:

* **Best case:** O(n²)
* **Average case:** O(n²)
* **Worst case:** O(n²)
* **Space complexity:** O(1) (in-place sort)

Let me know if you want a visual version or want to sort descending instead.


Great! Since you said **"yes"**, I’ll provide both a **visual version** of Selection Sort and a **descending order** version.

---

### 🎨 Visual Version (With Console Logs)

```javascript
function selectionSortVisual(arr) {
    const n = arr.length;

    for (let i = 0; i < n - 1; i++) {
        let minIndex = i;
        console.log(`\nStep ${i + 1}:`);
        console.log(`Start from index ${i}, current array: [${arr.join(', ')}]`);

        for (let j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex !== i) {
            console.log(`Swapping ${arr[i]} and ${arr[minIndex]}`);
            [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
        } else {
            console.log(`No swap needed for index ${i}`);
        }
        console.log(`Result after step ${i + 1}: [${arr.join(', ')}]`);
    }

    return arr;
}

const array1 = [64, 25, 12, 22, 11];
console.log("Final Sorted Array (Ascending):", selectionSortVisual(array1));
```

---

### 🔽 Selection Sort (Descending Order)

Just reverse the comparison:

```javascript
function selectionSortDescending(arr) {
    const n = arr.length;

    for (let i = 0; i < n - 1; i++) {
        let maxIndex = i;

        for (let j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex !== i) {
            [arr[i], arr[maxIndex]] = [arr[maxIndex], arr[i]];
        }
    }

    return arr;
}

// Example usage
const array2 = [64, 25, 12, 22, 11];
console.log("Sorted array (Descending):", selectionSortDescending(array2));  // Output: [64, 25, 22, 12, 11]
```

---

Would you like to see a **step-by-step animation in the browser** using HTML/CSS/JS as well?

Absolutely! Here's how you can implement **Selection Sort** in **C++**, including both **ascending** and **descending** order versions.

---

### ✅ Selection Sort in C++ (Ascending Order)

```cpp
#include <iostream>
using namespace std;

void selectionSortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the index of the smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum with the current element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSortAscending(arr, n);
    cout << "Sorted array in ascending order: ";
    printArray(arr, n);

    return 0;
}
```

---

### 🔽 Selection Sort in C++ (Descending Order)

Just flip the comparison:

```cpp
#include <iostream>
using namespace std;

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSortDescending(arr, n);
    cout << "Sorted array in descending order: ";
    printArray(arr, n);

    return 0;
}
```

---

Let me know if you'd like a **step-by-step visual explanation** in C++ too, or want to sort strings, structs, or use `vector<int>` instead of arrays.
