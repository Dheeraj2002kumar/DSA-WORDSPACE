function bubbleSort(arr){
    let n = arr.length;
    let swapped;

    do {
        swapped = false;
        for (let i = 1; i < n; i++){
            if (arr[i - 1] > arr[i]){
                // swap element
                [arr[i - 1], arr[i]] = [arr[i], arr[i - 1]];
                swapped = true;
            }
        }
        n--; // Optimization: largest element is at the end after each pass
    } while (swapped);

    return arr;
}

let numbers = [5, 3, 8, 4, 2];
console.log("Befor bubble sort: ", numbers);
console.log("After sorting: ",bubbleSort(numbers));