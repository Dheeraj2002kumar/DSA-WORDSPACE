function selectionSort(arr){
    const n = arr.length;

    for (let i = 0; i < n-1; i++){
        // Assume the current index is the smallest
        let minIndex = i;

        // find the index of the smallest element in the remainnig array
        for (let j = i+1; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex !== i){
            [arr[i], arr[minIndex]] = [arr[minIndex], arr[i]];
        }
    }

    return arr;
}

const array = [64, 52, 25, 12, 22, 11];
console.log("Sorted Array: ", selectionSort(array));

// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA /1_Sorting /1_Selection_Sort(main) $ node selectionSort.js 
// Sorted Array: [11, 12, 22, 25, 52, 64]