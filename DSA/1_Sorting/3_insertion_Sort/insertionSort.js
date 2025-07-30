function insertionSort(arr){
    for (let i = 1; i < arr.length; i++){
        let key = arr[i];
        let j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key into ints correct positiono
        arr[j + 1] = key;
    }

    return arr;
}

const array = [5, 2, 9, 1, 5, 6];
console.log("Before sorting: ", array);

const sorted = insertionSort(array);
console.log("After sorting: ", sorted);

// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA /1_Sorting /3_insertion_Sort(main) $ node insertionSort.js
// Before sorting: [5, 2, 9, 1, 5, 6]
// After sorting: [1, 2, 5, 5, 6, 9]
// @Dheeraj2002kumar ➜ .../DSA-WORDSPACE/DSA /1_Sorting /3_insertion_Sort(main) $ 