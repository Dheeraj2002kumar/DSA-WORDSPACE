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


