Here's a simple implementation of **Insertion Sort** in **JavaScript**:

```javascript
function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;

    // Move elements that are greater than key to one position ahead
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    // Insert the key into its correct position
    arr[j + 1] = key;
  }

  return arr;
}

// Example usage
const array = [5, 2, 9, 1, 5, 6];
const sorted = insertionSort(array);
console.log(sorted); // Output: [1, 2, 5, 5, 6, 9]
```

### How it works:

* The algorithm divides the array into a **sorted** and **unsorted** part.
* It repeatedly takes the first unsorted element and inserts it into the correct position in the sorted part.
* This is efficient for small or nearly sorted datasets but has **O(n²)** time complexity in the worst case.

Let me know if you want it visualized or want to sort objects by a key!


Great! Here's a simple **visualization of Insertion Sort** using **HTML + JavaScript**. This example displays bars representing array values and shows the sorting process step-by-step.

---

### 📊 Insertion Sort Visualization (HTML + JS)

You can copy and paste this into an `.html` file and open it in your browser:

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Insertion Sort Visualization</title>
  <style>
    body { font-family: sans-serif; background: #f0f0f0; }
    #array-container {
      display: flex;
      align-items: flex-end;
      height: 300px;
      border: 1px solid #ccc;
      margin-top: 20px;
      background: white;
      padding: 10px;
    }
    .bar {
      width: 20px;
      margin: 0 2px;
      background-color: steelblue;
      text-align: center;
      color: white;
    }
    button {
      margin-top: 20px;
    }
  </style>
</head>
<body>

<h2>Insertion Sort Visualization</h2>
<div id="array-container"></div>
<button onclick="startSort()">Start Sort</button>

<script>
  const container = document.getElementById('array-container');
  const array = Array.from({ length: 20 }, () => Math.floor(Math.random() * 100));
  
  function drawArray(arr, highlightIndex = -1) {
    container.innerHTML = '';
    arr.forEach((value, index) => {
      const bar = document.createElement('div');
      bar.classList.add('bar');
      bar.style.height = `${value * 2}px`;
      if (index === highlightIndex) {
        bar.style.backgroundColor = 'orange';
      }
      bar.textContent = value;
      container.appendChild(bar);
    });
  }

  async function startSort() {
    let arr = [...array];
    drawArray(arr);

    for (let i = 1; i < arr.length; i++) {
      let key = arr[i];
      let j = i - 1;

      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
        drawArray(arr, j + 1);
        await new Promise(resolve => setTimeout(resolve, 200)); // Delay for visualization
      }

      arr[j + 1] = key;
      drawArray(arr, j + 1);
      await new Promise(resolve => setTimeout(resolve, 200));
    }
  }

  drawArray(array); // Initial draw
</script>

</body>
</html>
```

---

### ✅ Features:

* Randomly generates 20 numbers (0–99).
* Visually represents values as vertical bars.
* Highlights the current bar being inserted.
* Animates the sorting process step-by-step with a short delay.

Want to add more interactivity like speed control or sorting different datasets (e.g. strings or objects)? I can help with that too.

