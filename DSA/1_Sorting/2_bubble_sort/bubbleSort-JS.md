Here's a simple implementation of **Bubble Sort in JavaScript**:

```javascript
function bubbleSort(arr) {
  let n = arr.length;
  let swapped;
  
  do {
    swapped = false;
    for (let i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        // Swap elements
        [arr[i - 1], arr[i]] = [arr[i], arr[i - 1]];
        swapped = true;
      }
    }
    n--; // Optimization: largest element is at the end after each pass
  } while (swapped);

  return arr;
}

// Example usage
let numbers = [5, 3, 8, 4, 2];
console.log(bubbleSort(numbers)); // Output: [2, 3, 4, 5, 8]
```

### How It Works:

* Repeatedly steps through the list.
* Compares adjacent pairs and swaps them if they're in the wrong order.
* Continues until a full pass is made without any swaps (meaning the array is sorted).

Let me know if you want a **descending sort**, **step-by-step visualization**, or an **in-place version without returning**.


Great — here's what you asked for:

---

### 🔄 Bubble Sort (Descending Order)

```javascript
function bubbleSortDescending(arr) {
  let n = arr.length;
  let swapped;

  do {
    swapped = false;
    for (let i = 1; i < n; i++) {
      if (arr[i - 1] < arr[i]) {
        [arr[i - 1], arr[i]] = [arr[i], arr[i - 1]];
        swapped = true;
      }
    }
    n--;
  } while (swapped);

  return arr;
}

// Example:
let nums = [5, 3, 8, 4, 2];
console.log(bubbleSortDescending(nums)); // Output: [8, 5, 4, 3, 2]
```

---

### 👣 Step-by-Step Visualization (Console Logs)

```javascript
function bubbleSortWithSteps(arr) {
  let n = arr.length;
  let swapped;
  let pass = 1;

  do {
    console.log(`Pass ${pass}:`, [...arr]);
    swapped = false;
    for (let i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        [arr[i - 1], arr[i]] = [arr[i], arr[i - 1]];
        swapped = true;
      }
    }
    n--;
    pass++;
  } while (swapped);

  console.log('Final sorted array:', arr);
  return arr;
}

// Example:
let array = [7, 1, 5, 2];
bubbleSortWithSteps(array);
```

---

### 🔁 In-Place Bubble Sort (No Return)

If you want the function to **sort the array without returning a new reference**:

```javascript
function bubbleSortInPlace(arr) {
  let n = arr.length;
  let swapped;

  do {
    swapped = false;
    for (let i = 1; i < n; i++) {
      if (arr[i - 1] > arr[i]) {
        [arr[i - 1], arr[i]] = [arr[i], arr[i - 1]];
        swapped = true;
      }
    }
    n--;
  } while (swapped);
}

// Example:
let arr = [9, 4, 6, 2];
bubbleSortInPlace(arr);
console.log(arr); // Output: [2, 4, 6, 9]
```

---

Let me know if you want to sort strings, objects (like by age), or visualize it in the browser with animations.

